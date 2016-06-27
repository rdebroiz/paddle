#pragma once

#include <QMainWindow>
#include <QSettings>

#include <itkImageFileReader.h>

template <class ImageType>
typename itk::SmartPointer<ImageType>
readImage(std::string filename)
{
    typedef itk::ImageFileReader<ImageType> ReaderType;
    typename ReaderType::Pointer reader = ReaderType::New();
    reader->SetFileName(filename);

    typename itk::SmartPointer<ImageType> img;

    reader->Update();

    img = reader->GetOutput();
    return img;
}


class PMainWindow: public QMainWindow
{
    Q_OBJECT

private:
    QSettings *m_settings;

public:
    PMainWindow(QWidget *parent = NULL);
    ~PMainWindow();

protected:
    virtual void closeEvent(QCloseEvent *event);


};
