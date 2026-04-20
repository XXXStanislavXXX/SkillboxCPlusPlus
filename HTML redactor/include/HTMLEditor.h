#ifndef HTMLEDITOR_H
#define HTMLEDITOR_H

#include <QMainWindow>
#include <QPlainTextEdit>
#include <QTextBrowser>

/**
 * @class HTMLEditor
 * @brief A real-time HTML editor with preview
 *
 * This class provides a split-window interface for editing HTML code
 * on the left side and viewing the rendered result on the right side.
 * Changes in the editor are reflected in the preview instantly.
 */
class HTMLEditor : public QMainWindow {
    Q_OBJECT

public:
    /**
     * @brief Constructs the HTMLEditor window
     * @param parent The parent widget (default: nullptr)
     */
    explicit HTMLEditor(QWidget *parent = nullptr);

private slots:
    /**
     * @brief Updates the HTML preview based on editor content
     *
     * This slot is called whenever the text in the editor changes.
     * It retrieves the text from the editor and displays it as rendered
     * HTML in the preview browser.
     */
    void updatePreview();

private:
    /**
     * @brief Initializes the user interface
     *
     * Sets up the main window layout with two widgets:
     * - Left: QPlainTextEdit for HTML code editing
     * - Right: QTextBrowser for HTML preview
     */
    void setupUI();

private:
    QPlainTextEdit *textEdit;      ///< Text editor for HTML code
    QTextBrowser *htmlPreview;     ///< Browser for HTML preview
};

#endif // HTMLEDITOR_H

