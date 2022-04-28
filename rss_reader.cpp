#include "rss_reader.h"
#include "rapidxml/rapidxml.hpp"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
using namespace rapidxml;

void rss_reader::read() {
    xml_document<> doc;
    xml_node<> * root_node;
    xml_node<> * channel_node;

    ifstream news("news.xml");

    vector<char> buffer((istreambuf_iterator<char>(news)), istreambuf_iterator<char>());
    buffer.push_back('\0');

    doc.parse<0>(&buffer[0]);

    root_node = doc.first_node("rss");
    channel_node = root_node->first_node("channel");

    int i = 0;
    for (xml_node<> * item_node = channel_node->first_node("item"); item_node; item_node = item_node->next_sibling()) {
        if (i == 3) {
            break;
        }
        cout << item_node->first_node()->first_node()->value() << endl;
        i++;
    }
}
