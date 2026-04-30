#include <string>
#include <iostream>

class system_stats
{
private:
    // Temps
    double temperatura_cpu;
    double temperatura_gpu;

    // loads%
    double cpu_load;
    double gpu_load;
    double ram_load;

    // Memory Stats
    double ram_used_gb;
    double vram_used_gb;

    // Energy
    double cpu_clock_mhz;
    double gpu_power_w;
public:
    system_stats();
    ~system_stats();

    std::string update_stats();

    // generic func to return a json response
    void read_windows();
    void read_windows_ram();
    void read_linux();
};


