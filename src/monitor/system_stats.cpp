#include "system_stats.hpp"

#ifdef _WIN32
    #include <windows.h>
#else 
    #include <fstream>
#endif


system_stats::system_stats()
{
    // Temps
    this->temperatura_cpu = 0.0;
    this->temperatura_gpu = 0.0;
    // loads%
    this->cpu_load = 0.0;
    this->gpu_load = 0.0;
    this->ram_load = 0.0;
    // Memory Stats
    this->ram_used_gb = 0.0;
    this->vram_used_gb = 0.0;
    // Energy
    this->cpu_clock_mhz = 0.0;
    this->gpu_power_w = 0.0;
}

system_stats::~system_stats() {}

std::string system_stats::update_stats()
{
    try {
        #ifdef _WIN32
            read_windows();
        #else
            read_linux();
        #endif
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return "{ \"erro\":\"system_stats_error_read\"}";
    }

    try {
        std::string statos = "{";
        statos += "\"cpu_temperature\":" + std::to_string(this->temperatura_cpu) + ",";
        statos += "\"gpu_temperature\":" + std::to_string(this->temperatura_gpu) + ",";
        statos += "\"cpu_load\":" + std::to_string(this->cpu_load) + ",";
        statos += "\"gpu_load\":" + std::to_string(this->gpu_load) + ",";
        statos += "\"ram_load\":" + std::to_string(this->ram_load) + ",";
        statos += "\"ram_used_gb\":" + std::to_string(this->ram_used_gb) + ",";
        statos += "\"vram_used_gb\":" + std::to_string(this->vram_used_gb) + ",";
        statos += "\"cpu_clock_mhz\":" + std::to_string(this->cpu_clock_mhz) + ",";
        statos += "\"gpu_power_w\":" + std::to_string(this->gpu_power_w);
        statos += "}";
        return statos;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return "{ \"erro\":\"system_stats_error\"}";
    }
}

void system_stats::read_windows()
{
    this->read_windows_ram();
}

void system_stats::read_windows_ram()
{
    MEMORYSTATUSEX memStatus;
    memStatus.dwLength = sizeof(MEMORYSTATUSEX);

    if (GlobalMemoryStatusEx(&memStatus)) {
        // Calcular RAM usada em GB
        ULONGLONG totalPhysical = memStatus.ullTotalPhys;
        ULONGLONG freePhysical = memStatus.ullAvailPhys;
        ULONGLONG usedPhysical = totalPhysical - freePhysical;

        this->ram_used_gb = usedPhysical / (1024.0 * 1024.0 * 1024.0);
        this->ram_load = memStatus.dwMemoryLoad; // Percentagem já calculada pelo Windows (0-100)
    }
}

void system_stats::read_linux()
{

}
