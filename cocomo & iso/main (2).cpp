#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

// Structures for Quality Planning
struct QualityObjective {
    string description;
    string metric;
    double targetValue;
};

struct ComplianceItem {
    string description;
    bool completed;
};

// Function to count LOC from file
int countLOC(const string &filename) {
    ifstream file(filename.c_str());
    if (!file.is_open()) {
        cerr << "File not found" << endl;
        return -1;
    }

    string line;
    int loc = 0;
    bool inComment = false;
    while (getline(file, line)) {
        string trimmed = line;
        trimmed.erase(0, trimmed.find_first_not_of(" \t"));
        if (trimmed.empty()) continue;
        if (trimmed.find("/*") != string::npos) inComment = true;
        if (inComment) {
            if (trimmed.find("*/") != string::npos) inComment = false;
            continue;
        }
        if (trimmed.substr(0, 2) == "//") continue;
        loc++;
    }

    file.close();
    return loc;
}

// COCOMO Estimation Function
void calculateCOCOMO(float kloc, float a, float b, float c, float d, const string &mode) {
    float effort = a * pow(kloc, b);
    float devTime = c * pow(effort, d);
    float staffing = effort / devTime;
    float productivity = kloc / effort;

    cout << "\n==============================\n";
    cout << "   " << mode << " Mode\n";
    cout << "==============================\n";

    cout << left << setw(20) << "Project Type"
         << setw(20) << "Effort (PM)"
         << setw(20) << "Dev Time (Months)"
         << setw(20) << "Avg. Staffing"
         << setw(20) << "Productivity" << endl;

    cout << string(95, '-') << endl;

    cout << left << setw(20) << mode
         << setw(20) << fixed << setprecision(2) << effort
         << setw(20) << fixed << setprecision(2) << devTime
         << setw(20) << fixed << setprecision(2) << staffing
         << setw(20) << fixed << setprecision(4) << productivity
         << endl;
}

// ISO Quality Planning Functions
void displayQualityObjectives(const vector<QualityObjective>& objectives) {
    cout << "\n===== ISO Quality Objectives =====\n";
    cout << string(95, '-') << endl;
    cout << left << setw(35) << "Objective" << setw(30) << "Metric" << setw(20) << "Target" << endl;
    cout << string(95, '-') << endl;

    // ? Correct iteration using const auto&
    for (const auto& obj : objectives) {
        cout << left << setw(35) << obj.description
             << setw(30) << obj.metric
             << setw(20) << obj.targetValue
             << endl;
    }

    cout << string(95, '-') << endl;
}

void displayComplianceChecklist(const vector<ComplianceItem>& checklist) {
    cout << "\n===== Compliance Checklist =====\n";
    cout << string(95, '-') << endl;
    cout << left << setw(70) << "Task" << setw(20) << "Completed" << endl;
    cout << string(95, '-') << endl;

    for (const auto& item : checklist) {
        cout << left << setw(70) << item.description
             << setw(20) << (item.completed ? "Yes" : "No")
             << endl;
    }

    cout << string(95, '-') << endl;
}

int main() {
    string filename;
    cout << "Enter the file path (use double backslashes \\\\ or forward slashes /): ";
    getline(cin, filename);

    int loc = countLOC(filename);
    if (loc < 0) return 1;

    float kloc = loc / 1000.0;
    cout << "\nTotal LOC: " << loc << endl;
    cout << "KLOC     : " << fixed << setprecision(2) << kloc << endl;

    int choice;
    cout << "\nSelect COCOMO Mode:\n1. Organic\n2. Semi-Detached\n3. Embedded\n4. All Modes\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            calculateCOCOMO(kloc, 2.4, 1.05, 2.5, 0.38, "Organic");
            break;
        case 2:
            calculateCOCOMO(kloc, 3.0, 1.12, 2.5, 0.35, "Semi-Detached");
            break;
        case 3:
            calculateCOCOMO(kloc, 3.6, 1.20, 2.5, 0.32, "Embedded");
            break;
        case 4:
            calculateCOCOMO(kloc, 2.4, 1.05, 2.5, 0.38, "Organic");
            calculateCOCOMO(kloc, 3.0, 1.12, 2.5, 0.35, "Semi-Detached");
            calculateCOCOMO(kloc, 3.6, 1.20, 2.5, 0.32, "Embedded");
            break;
        default:
            cout << "Invalid choice!" << endl;
            return 1;
    }

    vector<QualityObjective> objectives = {
        {"Defect Density", "defects/KLOC", 0.5},
        {"Requirements Traceability", "%", 100.0},
        {"Complaint Response Time", "days", 5.0}
    };

    vector<ComplianceItem> checklist = {
        {"Requirements validation documented", true},
        {"Design review performed", false},
        {"Testing covers all requirements", true},
        {"ISO audit completed for this phase", false}
    };

    displayQualityObjectives(objectives);
    displayComplianceChecklist(checklist);

    cout << "\nProgram Completed Successfully!" << endl;
    return 0;
}
