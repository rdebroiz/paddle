#include "MainWindow.h"


#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QString>
#include <QFileDialog>


#include <itkImageFileReader.h>
#include <itkImageToVTKImageFilter.h>


MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent)
{
     m_settings = new QSettings(QSettings::IniFormat, QSettings::UserScope, "Inria", "paddle", this);

    QWidget *centralWidget = new QWidget;
    QHBoxLayout *centralLayout  = new QHBoxLayout;

    centralWidget->setLayout(centralLayout);
    this->setCentralWidget(centralWidget);

    QVBoxLayout *toolLayout = new QVBoxLayout;
    centralLayout->addLayout(toolLayout);

    QPushButton *openButton = new QPushButton("open");
    toolLayout->addWidget(openButton);

    connect(openButton, &QPushButton::clicked,
            this, &MainWindow::openImage);

    m_view = new PVtkView;
    centralLayout->addWidget(m_view);

    this->restoreGeometry(m_settings->value("mainwindow/geometry").toByteArray());
}

MainWindow::~MainWindow()
{

}

void MainWindow::openImage()
{
    //  get last directory opened in settings.
    QString path;
    QFileDialog dialog(this);

    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setViewMode(QFileDialog::Detail);
    dialog.restoreState(m_settings->value("openimagedialog/filename").toByteArray());
    dialog.restoreGeometry(m_settings->value("openimagedialog/geometry").toByteArray());
    if(dialog.exec())
        path = dialog.selectedFiles().first();


    if (path.isEmpty())
        return;

    typedef itk::Image<float, 3> ImageType;
    typedef itk::ImageFileReader<ImageType> ReaderType;
    typename ReaderType::Pointer reader = ReaderType::New();
    reader->SetFileName(path.toStdString().c_str());

    typename itk::SmartPointer<ImageType> img;
    reader->Update();

    img = reader->GetOutput();

    typedef itk::ImageToVTKImageFilter<ImageType> ConverterType;
    typename ConverterType::Pointer myConverter = ConverterType::New();
    myConverter->SetInput(img);
    myConverter->Update();
    myConverter->UpdateOutputInformation();

    vtkImageData *data = myConverter->GetOutput();
    m_view->addData(data);

    //  save last directory opened in settings.
    m_settings->setValue("openimagedialog/filename", path);
}

vtkImageData *MainWindow::vtkitkToVtkImage(const QString &filename)
{

    typedef itk::Image<float, 3> ImageType;
    typedef itk::ImageFileReader<ImageType> ReaderType;
    typename ReaderType::Pointer reader = ReaderType::New();
    reader->SetFileName(filename.toStdString().c_str());

    typename itk::SmartPointer<ImageType> img;
    reader->Update();

    img = reader->GetOutput();

    typedef itk::ImageToVTKImageFilter<ImageType> ConverterType;
    typename ConverterType::Pointer myConverter = ConverterType::New();
    myConverter->SetInput (img);
    myConverter->Update();

    return myConverter->GetOutput();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    m_settings->setValue("mainwindow/geometry", this->saveGeometry());
}
