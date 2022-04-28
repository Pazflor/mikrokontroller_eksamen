#include "json_parse.h"
#include "rapidjson/document.h"
#include "rapidjson/istreamwrapper.h"

#include <iostream>
#include <fstream>

using namespace std;
using namespace rapidjson;

void json_parse::parser() {

    // Open the file as a stream
    std::ifstream ifs("data.json");

    if (!ifs.is_open())
    {
        std::cout << "Error: Failed to open file. Exiting." << std::endl;
    }

    // Convert the stream to the rapidjson stream type
    rapidjson::IStreamWrapper isw(ifs);

    // Create JSON document object
    rapidjson::Document doc;

    // Read the JSON document into memory
    doc.ParseStream(isw);

    // Get the object at the top level of the document
    const auto &obj = doc.GetObject();

    // Weather object
    const auto &weather = obj["weather"].GetArray();
    string desc = weather[0]["description"].GetString();
    desc[0] = toupper(desc[0]);

    const auto &main = obj["main"].GetObject();
    const auto temp = main["temp"].GetFloat() - 273.15;

    printf("%s\n%.1f C degrees\n", desc.c_str(), temp);
}
