#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double dataRate;  // e.g., 6000 for DDR5-6000
    double tCL, tRCD, tRP, tRAS;

    cout << "=== DDR RAM Latency Calculator ===\n";
    cout << "Enter data rate (MT/s, e.g. 6000 for DDR5-6000): ";
    cin >> dataRate;

    cout << "Enter timings (CL tRCD tRP tRAS) separated by spaces (e.g. 38 46 46 76): ";
    cin >> tCL >> tRCD >> tRP >> tRAS;

    // Step 1: Convert data rate to real clock (since DDR transfers twice per cycle)
    double clockMHz = dataRate / 2.0;

    // Step 2: Calculate cycle time (ns)
    double cycleTime = 1000.0 / clockMHz; // ns per cycle

    // Step 3: Calculate each timing in ns
    double cl_ns   = tCL  * cycleTime;
    double rcd_ns  = tRCD * cycleTime;
    double rp_ns   = tRP  * cycleTime;
    double ras_ns  = tRAS * cycleTime;

    // Step 4: Estimate total random-access latency (CL + tRCD)
    double totalLatency = (tCL + tRCD) * cycleTime;

    cout << fixed << setprecision(3);
    cout << "\n--- Results ---\n";
    cout << "Data Rate: DDR" << dataRate << "\n";
    cout << "Clock Speed: " << clockMHz << " MHz\n";
    cout << "Cycle Time: " << cycleTime << " ns\n";
    cout << "\nTimings in Nanoseconds:\n";
    cout << "  CAS Latency (tCL): " << cl_ns << " ns\n";
    cout << "  Row to Column Delay (tRCD): " << rcd_ns << " ns\n";
    cout << "  Row Precharge (tRP): " << rp_ns << " ns\n";
    cout << "  Row Active Time (tRAS): " << ras_ns << " ns\n";
    cout << "\nEstimated Total Random Access Latency: " << totalLatency << " ns\n";

    cout << "\n==============================\n";
    cout << "Tip: Lower total latency = better performance.\n";
    cout << "==============================\n";

    return 0;
}
