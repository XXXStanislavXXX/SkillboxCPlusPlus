#include "html_parser.h"
#include <cpr/cpr.h>

std::string fetch_html_page(const std::string& url) {
    cpr::Response response = cpr::Get(
        cpr::Url{url},
        cpr::Header{{"accept", "text/html"}}
    );
    
    return response.text;
}

std::string extract_tag_content(const std::string& html, const std::string& tag_name) {
    std::string opening_tag = "<" + tag_name + ">";
    std::string closing_tag = "</" + tag_name + ">";
    
    size_t start_pos = html.find(opening_tag);
    if (start_pos == std::string::npos) {
        return "";
    }
    
    start_pos += opening_tag.length();
    size_t end_pos = html.find(closing_tag, start_pos);
    
    if (end_pos == std::string::npos) {
        return "";
    }
    
    return html.substr(start_pos, end_pos - start_pos);
}
