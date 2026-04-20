#include "HTMLEditor.h"
#include <QWidget>
#include <QHBoxLayout>
#include <QSizePolicy>

HTMLEditor::HTMLEditor(QWidget *parent)
    : QMainWindow(parent)
    , textEdit(nullptr)
    , htmlPreview(nullptr)
{
    setWindowTitle("HTML Editor by Stas");
    resize(1200, 600);

    setupUI();
}

void HTMLEditor::setupUI()
{
    // Create central widget
    auto *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Create horizontal layout
    auto *layout = new QHBoxLayout(centralWidget);
    layout->setContentsMargins(0, 0, 0, 0);

    // Create text editor for HTML code
    textEdit = new QPlainTextEdit(this);
    const QString defaultHtml = R"(
<html>
<head>
    <title>Hello</title>
</head>
<body>
    <h1>Hello GBrains!</h1>
    <p>Edit HTML code!</p>
</body>
</html>
)";
    textEdit->setPlainText(defaultHtml);
    textEdit->setStyleSheet("font-family: Consolas, 'Courier New'; font-size: 12pt;");

    // Set size policy for text editor
    textEdit->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Create HTML preview browser
    htmlPreview = new QTextBrowser(this);
    htmlPreview->setStyleSheet("background-color: white; color: black;");

    // Set size policy for preview
    htmlPreview->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Add widgets to layout
    layout->addWidget(textEdit);
    layout->addWidget(htmlPreview);

    // Set equal stretch factors for both widgets
    layout->setStretchFactor(textEdit, 1);
    layout->setStretchFactor(htmlPreview, 1);

    // Connect text change signal to preview update
    connect(textEdit, &QPlainTextEdit::textChanged, this, &HTMLEditor::updatePreview);

    // Show initial HTML
    updatePreview();
}

void HTMLEditor::updatePreview()
{
    QString html = textEdit->toPlainText();
    htmlPreview->setHtml(html);
}

