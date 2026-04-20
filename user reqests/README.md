# HTTP Client for httpbin.org

A simple command-line HTTP client that demonstrates different types of HTTP requests using the CPR library.

## Description

This application allows users to interact with the httpbin.org service through various HTTP methods. The program provides an interactive command-line interface where users can execute GET, POST, PUT, DELETE, and PATCH requests.

## Features

- **GET requests**: Retrieve data from the server
- **POST requests**: Send data to the server
- **PUT requests**: Update existing data
- **DELETE requests**: Remove data from the server
- **PATCH requests**: Partially modify data
- **Interactive CLI**: Simple command-based interface
- **Response display**: Shows status codes and response bodies

## Requirements

- C++17 or higher
- CMake 3.14 or higher
- Internet connection
- CPR library (automatically fetched during build)

## Available commands:

get - Execute GET request
post - Execute POST request
put - Execute PUT request
delete - Execute DELETE request
patch - Execute PATCH request
exit - Exit the program

## Example Session

HTTP Client for httpbin.org
Available commands: get, post, put, delete, patch, exit

Enter command: get
Status code: 200
Response:
{
"args": {},
"headers": {...},
...
}

Enter command: exit
Exiting program...
