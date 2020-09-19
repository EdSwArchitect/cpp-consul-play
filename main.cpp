#include <iostream>

#include "oatpp/network/server/Server.hpp"
#include "oatpp-consul/Client.hpp"

#include "oatpp/web/client/HttpRequestExecutor.hpp"
#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/web/server/HttpRouter.hpp"
#include "oatpp/network/client/SimpleTCPConnectionProvider.hpp"
#include "oatpp/network/server/SimpleTCPConnectionProvider.hpp"

#include "oatpp/parser/json/mapping/Serializer.hpp"
#include "oatpp/parser/json/mapping/Deserializer.hpp"

#include "oatpp/core/macro/component.hpp"


int main(int argc, char** argv) {
    std::cout << "Hello, World!" << std::endl;

//    oatpp::base::Environment::init();

//    std::cout << "\nEnvironment:\n";

    auto connectionProvider = oatpp::network::client::SimpleTCPConnectionProvider::createShared("localhost", 8500);

    auto requestExecutor = oatpp::web::client::HttpRequestExecutor::createShared(connectionProvider);

    auto client = oatpp::consul::Client::createShared(requestExecutor);

    bool code = client->kvPut("name", "Edwin Kenton Brown\n200 meter sprinter");

    std::cout << "Put key: " << code << std::endl;

    if (!code) {

        auto value = client->kvGet("name");

        std::cout << "\tReturned: '" << value->std_str() << "'" << std::endl;

        auto metadata = client->kvGetMetadata("name");

        std::cout << "\tMetadata value: '" << metadata->value->std_str() << "'" << std::endl;

        std::cout << "\tFlags: " << metadata->flags << std::endl;
    }

    std::cout << "Use count: " << client.use_count() << std::endl;

//    oatpp::base::Environment::destroy();

    return 0;
}