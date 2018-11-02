/**
 * html.h
 *
 * This file contains functions concerning HTML (templates).
 */

#ifndef ALLY_HTML_H
#define ALLY_HTML_H

#include <cstdio>
#include <string>
#include <boost/filesystem.hpp>
#include <mstch/mstch.hpp>


namespace fs = boost::filesystem;


/*
 * Get HTML
 *
 * Retrieve the contents of an HTML file. This function actually works for all file types.
 *
 * @param filename - The filename of the targeted file.
 * @return - The contents of the file as a std::string.
 */
std::string get_html(std::string filename) {

    fs::path project_path = fs::current_path().parent_path();

    fs::path dir("templates");
    fs::path file(filename);
    fs::path full_path = project_path / dir / file;

    std::ifstream ifs(full_path.string());
    std::string content( (std::istreambuf_iterator<char>(ifs) ),
                         (std::istreambuf_iterator<char>() ) );

    return content;
}


/**
 * Render
 *
 * Render an HTML page using the contents of an HTML-file/template and a context. The content of the context is used to
 * fill the template's tags.
 *
 * @param html_file_contents - The HTML template to fill.
 * @param context - Data to fill the webpage.
 * @return - A filled HTML page.
 */
std::string render(std::string html_file_contents, mstch::map context) {
    return mstch::render(html_file_contents, context);
}


#endif //ALLY_HTML_H
