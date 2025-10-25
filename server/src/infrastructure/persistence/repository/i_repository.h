//
// Created by roger on 10/25/25.
//

#ifndef I_REPOSITORY_H
#define I_REPOSITORY_H
#include <string>
#include <vector>


/* Interface for all persistables, all persistables should implement this interface */
template <typename T>
class IRepository {
public:
    virtual ~IRepository() = default;

    // Create / Insert
    virtual void create(const T& entity) = 0;

    // Read
    virtual T read(const std::string& id) = 0;
    virtual std::vector<T> readAll() = 0;

    // Update
    virtual void update(const T& entity) = 0;

    // Delete
    virtual void remove(const std::string& id) = 0;
};




#endif //I_REPOSITORY_H
