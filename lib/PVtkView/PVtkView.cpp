#include "PVtkView.h"

#include <QVBoxLayout>

#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRendererCollection.h>

#include <vtkImageMapper3D.h>
#include <vtkImageActor.h>
#include <vtkDataSetMapper.h>

#include <vtkGenericRenderWindowInteractor.h>

#include "PVtkGraphicsView.h"
#include "PVtkGraphicsItem.h"

class PVtkViewPrivate
{
public:
    Q_DISABLE_COPY(PVtkViewPrivate)
    Q_DECLARE_PUBLIC(PVtkView)

    vtkGenericOpenGLRenderWindow *renwin;
    vtkRenderer *axRen;

    PVtkView *q_ptr;
    PVtkViewPrivate(PVtkView *q)
        :q_ptr(q)
    {
        renwin = NULL;
    }

};

PVtkView::PVtkView(QWidget *parent)
    : QWidget(parent), d_ptr(new PVtkViewPrivate(this))
{
    Q_D(PVtkView);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    this->setLayout(mainLayout);

    PVtkGraphicsView *graphicsView = new PVtkGraphicsView(this);
    mainLayout->addWidget(graphicsView);

    d->renwin = vtkGenericOpenGLRenderWindow::New();
    graphicsView->item()->SetRenderWindow(d->renwin);

    d->axRen = vtkRenderer::New();
    d->axRen->SetBackground(0,0,0);

    d->renwin->AddRenderer(d->axRen);
}

PVtkView::~PVtkView()
{

}

void PVtkView::addData(vtkImageData *data)
{
    Q_D(PVtkView);

    //    vtkImageActor *actor = vtkImageActor::New();
    //    actor->GetMapper()->SetInputData(data);

    //    d->axRen->AddActor(actor);

    vtkSmartPointer<vtkDataSetMapper> mapper = vtkSmartPointer<vtkDataSetMapper>::New();
    mapper->SetInputData(data);

    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);


    // Add both renderers to the window
    d->renwin->AddRenderer(d->axRen);

    // Add a sphere to the left and a cube to the right
    d->axRen->AddActor(actor);

    d->axRen->ResetCamera();

    vtkSmartPointer<vtkGenericRenderWindowInteractor> renderWindowInteractor = vtkSmartPointer<vtkGenericRenderWindowInteractor>::New();
    renderWindowInteractor->SetRenderWindow(d->renwin);
    d->renwin->Render();
    renderWindowInteractor->Start();

}
