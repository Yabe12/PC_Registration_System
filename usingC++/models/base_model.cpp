// --- models/base_model.cpp ---
#include <pqxx/pqxx>
#include "../database/db_connection.cpp"

class BaseModel {
protected:
    pqxx::connection* db;

public:
    BaseModel() : db(Database::connect()) {}
    virtual ~BaseModel() = default;
};
