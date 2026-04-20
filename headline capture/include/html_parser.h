#ifndef HTML_PARSER_H
#define HTML_PARSER_H

#include <string>

/**
 * Fetches HTML page from the specified URL with accept header
 * @param url The URL to fetch from
 * @return HTML content as string
 */
std::string fetch_html_page(const std::string& url);

/**
 * Extracts text between HTML tags
 * @param html The HTML content
 * @param tag_name The tag name (e.g., "h1")
 * @return Extracted text or empty string if not found
 */
std::string extract_tag_content(const std::string& html, const std::string& tag_name);

#endif // HTML_PARSER_H
