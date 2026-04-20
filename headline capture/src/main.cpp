#include <iostream>
#include "html_parser.h"

int main() {
    const std::string url = "https://httpbin.org/html";

    std::cout << "Fetching HTML page from " << url << "...\n";

    std::string html_content = fetch_html_page(url);

    std::string h1_content = extract_tag_content(html_content, "h1");

    if (!h1_content.empty()) {
        std::cout << "Page heading: " << h1_content << std::endl;
    } else {
        std::cout << "No h1 tag found" << std::endl;
    }

    return 0;
}
