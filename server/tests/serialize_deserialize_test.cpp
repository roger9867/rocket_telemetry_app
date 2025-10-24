#include <gtest/gtest.h>

#include "flightlog_service.h"
#include "flight_log.h"
#include "json.hpp"
#include "api/dto/flightlog_serializable.h"
#include "domain/user.h"   // Beispiel: Header aus deinem Projekt
#include "domain/client.h"

using Json = nlohmann::json;

class UserTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Optional: Setup-Code vor jedem Test
    }

    void TearDown() override {
        // Optional: Aufräumarbeiten nach jedem Test
    }
};


TEST(SerializeDeserializeTest, TEST_SERIALIZE_FLIGHTLOG) {
    std::shared_ptr<RocketDesign> design = std::make_shared<RocketDesign>(
        "design_test_id",
        "design_test_name",
        "design_test_description"
    );

    std::unique_ptr<FlightLogSerializable> flightlog = std::make_unique<FlightLogSerializable>(
         "TEST_FLIGHTLOG_ID",
         FlightLogService::string_to_timestamp("2025-12-1 16:12:14"),
         design
    );

    Json flightlog_json = flightlog->serialize();
    Json expected = { {"id", "TEST_FLIGHTLOG_ID"} };
    EXPECT_EQ(flightlog_json, expected);

    flightlog_json = flightlog->serialize(JsonSerializable::SerializationMode::OneLevel);
    expected = {
        {"id", "TEST_FLIGHTLOG_ID"},
        {"design_id", "design_test_id"},
        {"timestamp", "2025-12-01 16:12:14"}
    };
    EXPECT_EQ(flightlog_json, expected);
}

TEST(SerializeDeserializeTest, TEST_DESERIALIZE_FLIGHTLOG) {
    Json flightlog = {
        {"id", "TEST_FLIGHTLOG_ID"},
        {"design_id", "design_test_id"},
        {"timestamp", "2025-12-01 16:12:14"}
    };

    FlightLogSerializable flight_log_serializable;
    flight_log_serializable.deserialize(flightlog);

    std::shared_ptr<RocketDesign> design = std::make_shared<RocketDesign>(
        "design_test_id",
        "design_test_name",
        "design_test_description"
    );

    std::unique_ptr<FlightLogSerializable> flightlog_expected = std::make_unique<FlightLogSerializable>(
        "TEST_FLIGHTLOG_ID",
        FlightLogService::string_to_timestamp("2025-12-01 16:12:14"),
        design
    );

    EXPECT_EQ(flight_log_serializable.log_id, flightlog_expected->log_id);
    EXPECT_EQ(flight_log_serializable.timestamp, flightlog_expected->timestamp);

    // design überprüfen
    //EXPECT_EQ(flight_log_serializable.design->id, "design_test_id");
    //EXPECT_EQ(flight_log_serializable.design->name, "design_test_name");
    //EXPECT_EQ(flight_log_serializable.design->description, "design_test_description");
}
