#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <chrono>
#include <sstream>

using namespace std;

class Task {
protected:
    string id;
    string timestamp;

    string getTimestamp() const {
        auto now = chrono::system_clock::now();
        time_t now_time = chrono::system_clock::to_time_t(now);
        string ts = ctime(&now_time);
        ts.pop_back(); 
        return ts;
    }

public:
    Task(string taskId) : id(taskId) {
        timestamp = getTimestamp();
    }
    
    virtual ~Task() = default; 
    virtual string execute() = 0; 
    
    string getId() const { return id; }
};

class ComputeTask : public Task {
    int base;
    int multiplier;

public:
    ComputeTask(string taskId, int b, int m) : Task(taskId), base(b), multiplier(m) {}

    string execute() override {
        int result = base * multiplier; 
        
        ostringstream log;
        log << "[" << timestamp << "] COMPUTE (" << id << "): "
            << base << " * " << multiplier << " = " << result;
                  
        return log.str();
    }
};

class DataProcessingTask : public Task {
    string raw_data;

public:
    DataProcessingTask(string taskId, string data) : Task(taskId), raw_data(data) {}

    string execute() override {
        string processed = raw_data;
        for (char &c : processed) {
            if (c >= 'a' && c <= 'z') {
                c -= 32; 
            }
        }
        
        ostringstream log;
        log << "[" << timestamp << "] DATA (" << id << "): "
            << "Cleaned -> '" << processed << "'";
                  
        return log.str();
    }
};

class Pipeline {
    vector<unique_ptr<Task>> queue;
    string log_file;

public:
    Pipeline(string path) : log_file(path) {}

    void addTask(unique_ptr<Task> t) {
        queue.push_back(move(t));
    }

    void run() {
        if (queue.empty()) {
            cout << "Pipeline is empty. Nothing to run!" << endl;
            return;
        }

        ofstream file(log_file, ios::app); 
        
        if (!file.is_open()) {
            cout << "Error: Couldn't open the log file!" << endl;
            return; 
        }

        file << "--- PIPELINE START ---\n";

        for (const auto& task : queue) {
            file << task->execute() << "\n";
        }

        file << "--- PIPELINE END ---\n\n";
        file.close();
        
        cout << "Success! Check " << log_file << " for the output." << endl;
    }
};

int main() {
    Pipeline engine("execution_engine.log");
    int choice;
    int computeCounter = 1;
    int dataCounter = 1;

    cout << "=== Dynamic Execution Engine ===\n";

    while (true) {
        cout << "\nQueue a task:\n";
        cout << "1. Compute Task (Math)\n";
        cout << "2. Data Processing Task (Text)\n";
        cout << "3. Run Pipeline & Exit\n";
        cout << "Choice: ";
        
        if (!(cin >> choice)) {
            
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice == 1) {
            int base, mult;
            cout << "Enter base number: ";
            cin >> base;
            cout << "Enter multiplier: ";
            cin >> mult;
            
            
            string id = "CTX-" + to_string(computeCounter++);
            engine.addTask(make_unique<ComputeTask>(id, base, mult));
            cout << "> Compute Task Added!\n";

        } else if (choice == 2) {
            string text;
            cout << "Enter text to process: ";
            
            
            cin.ignore(10000, '\n'); 
            getline(cin, text);
            
            string id = "DTX-" + to_string(dataCounter++);
            engine.addTask(make_unique<DataProcessingTask>(id, text));
            cout << "> Data Task Added!\n";

        } else if (choice == 3) {
            break; 
        } else {
            cout << "Invalid choice. Pick 1, 2, or 3.\n";
        }
    }

    cout << "\nRunning pipeline..." << endl;
    engine.run();

    return 0;
}
