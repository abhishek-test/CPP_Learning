#include <iostream>
#include <memory>
#include <string>

// 1. The Resource: Database Connection
class DatabaseConnection {
private:
    std::string dbName_;
public:
    explicit DatabaseConnection(const std::string& name) : dbName_(name) {
        std::cout << "[Database] Connected to: " << dbName_ << "\n";
    }

    ~DatabaseConnection() {
        std::cout << "[Database] Disconnected from: " << dbName_ << "\n";
    }

    void executeQuery(const std::string& query) const {
        std::cout << "Executing: " << query << "\n";
    }
};

// 2. The Consumer: Query Worker sharing the connection
class QueryWorker {
private:
    std::string workerName_;
    std::shared_ptr<DatabaseConnection> dbConnection_; // Shares ownership

public:
    QueryWorker(std::string name, std::shared_ptr<DatabaseConnection> conn)
        : workerName_(std::move(name)), dbConnection_(std::move(conn)) {
    }

    void performTask(const std::string& query) const {
        std::cout << "[" << workerName_ << "] ";
        dbConnection_->executeQuery(query);
    }
};

int main() {
    std::cout << "--- Starting Application ---\n";

    // Create a shared database connection. Reference count = 1
    auto sharedDb = std::make_shared<DatabaseConnection>("UserDatabase_Prod");

    {
        std::cout << "\nSpawning workers...\n";

        // Worker 1 takes a shared handle. Reference count = 2
        QueryWorker worker1("AuthService", sharedDb);

        // Worker 2 takes a shared handle. Reference count = 3
        QueryWorker worker2("LoggerService", sharedDb);

        std::cout << "Active shared handles (use_count): " << sharedDb.use_count() << "\n";

        worker1.performTask("SELECT * FROM Users WHERE id = 42;");
        worker2.performTask("INSERT INTO ActivityLog VALUES ('Login');");

        std::cout << "\nWorkers finishing up and leaving scope...\n";
    }
    // Both workers are destroyed here. Reference count drops back to 1.

    std::cout << "Shared handles remaining in main: " << sharedDb.use_count() << "\n";
    std::cout << "Shutting down main function...\n";
}
// sharedDb goes out of scope here. Reference count hits 0, 
// and the DatabaseConnection destructor is automatically called.