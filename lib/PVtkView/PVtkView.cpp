#include "PVtkView.h"

#include <QVBoxLayout>

#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRendererCollection.h>

#include <vtkImageMapper.h>
#include <vtkImageActor.h>

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

    vtkImageMapper *mapper = vtkImageMapper::New();
    mapper->SetInputData(data);

    vtkImageActor *actor = vtkImageActor::New();

    d->axRen->AddActor(actor);
}
