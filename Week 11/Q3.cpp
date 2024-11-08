#include <iostream>

// ---- Singleton Pattern ----
// The ConfigurationManager class ensures only one instance is created.
class ConfigurationManager {
private:
    static ConfigurationManager* instance;  // Pointer to the single instance

    // Private constructor to prevent creating objects outside the class
    ConfigurationManager() : configValue("Default Config") {}

public:
    std::string configValue;

    // Static method to get the single instance of ConfigurationManager
    static ConfigurationManager* getInstance() {
        if (instance == NULL) {  // Use NULL instead of nullptr
            instance = new ConfigurationManager();
        }
        return instance;
    }

    void printConfig() {
        std::cout << "Configuration Value: " << configValue << std::endl;
    }
};

// Initialize the static instance pointer to null
ConfigurationManager* ConfigurationManager::instance = NULL;


// ---- Factory Method Pattern ----
// Base class for Documents
class Document {
public:
    virtual void print() const = 0; // Pure virtual function
    virtual ~Document() = default;
};

// Concrete Product 1: PDFDocument
class PDFDocument : public Document {
public:
    void print() const override {
        std::cout << "Printing PDF Document" << std::endl;
    }
};

// Concrete Product 2: WordDocument
class WordDocument : public Document {
public:
    void print() const override {
        std::cout << "Printing Word Document" << std::endl;
    }
};

// Creator class: Abstract class for document factories
class DocumentFactory {
public:
    virtual Document* createDocument() const = 0;
    virtual ~DocumentFactory() = default;
};

// Concrete Creator 1: PDFDocumentFactory
class PDFDocumentFactory : public DocumentFactory {
public:
    Document* createDocument() const override {
        return new PDFDocument();
    }
};

// Concrete Creator 2: WordDocumentFactory
class WordDocumentFactory : public DocumentFactory {
public:
    Document* createDocument() const override {
        return new WordDocument();
    }
};

int main() {
    // ---- Singleton Example ----
    std::cout << "Singleton Example:\n";
    ConfigurationManager* configManager = ConfigurationManager::getInstance();
    configManager->printConfig();  // Should print the default configuration

    // Modify configuration value
    configManager->configValue = "Updated Config Value";
    configManager->printConfig();  // Should print the updated configuration

    std::cout << "\n";

    // ---- Factory Method Example ----
    std::cout << "Factory Method Example:\n";
    
    // Creating a PDF document using PDFDocumentFactory
    DocumentFactory* pdfFactory = new PDFDocumentFactory();
    Document* pdfDoc = pdfFactory->createDocument();
    pdfDoc->print();  // Should print "Printing PDF Document"
    
    // Creating a Word document using WordDocumentFactory
    DocumentFactory* wordFactory = new WordDocumentFactory();
    Document* wordDoc = wordFactory->createDocument();
    wordDoc->print();  // Should print "Printing Word Document"
    
    // Clean up
    delete pdfFactory;
    delete wordFactory;
    delete pdfDoc;
    delete wordDoc;

    return 0;
}

