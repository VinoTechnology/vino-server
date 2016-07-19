//2014_7_28  发动机三维结构展示
#include "AppEngineClient.h"
#include <osgDB/ReadFile>
#include "Global.h"



AppEngineClient::AppEngineClient(ViewpointMgrTask* vt):Client(vt)
{

}
AppEngineClient::~AppEngineClient()
{
	cout<<"App 客户端执行析构"<<endl;
}
osg::ref_ptr<osg::Node> AppEngineClient::DeepCopyModelData(osg::Node* node)
{
	//_node=new osg::Group(*node->asGroup(),osg::CopyOp::DEEP_COPY_ALL);
	//_node=osgDB::readNodeFile("D:\\sceneData\\engine2.osg");
	osg::CopyOp cp(osg::CopyOp::DEEP_COPY_ALL);
	_node=cp(node);
	addTransfromCallback();
	return _node;
}
void AppEngineClient::addTransfromCallback()
{
	MatrixTransformExtractor nv(this);
	//std::cout<<"_node.get()getname()::::::::::::::::::::"<<_node.get()->getName()<<std::endl;
	_node.get()->accept(nv);
}

AppEngineClient::TransfromCallback::TransfromCallback(AppEngineClient* thiz):thiz(thiz)
{
	velocity=10.0f;
	step=0.5;
	max_distance=5700;
	distance_07=0;
	distance_06=0;
	distance_05=0;
	distance_04=0;
	distance_03=0;
	distance_02=0;
	distance_01=0;
	distance_00=0;
	distance_0_=0;
	first=true;

}
void AppEngineClient::TransfromCallback::operator() (osg::Node* node, osg::NodeVisitor* nv)
{
	osg::MatrixTransform* t=dynamic_cast<osg::MatrixTransform* > (node);

	if(nv && t)
	{
		
		//std::cout<<"tgetname()::::::::::::::::::::"<<t->getName()<<std::endl;
		//std::cout<<"thizgetname()::::::::::::::::::::"<<thiz->getMatrixFormNodename()<<std::endl;
		if(t->getName() == thiz->getMatrixFormNodename() && thiz->getIsMatrixForm())
		{
		    //std::cout<<"tgetname()::::::::::::::::::::"<<t->getName()<<std::endl;
		    //std::cout<<"thizgetname()::::::::::::::::::::"<<thiz->getMatrixFormNodename()<<std::endl;
			osg::Matrixd mat=t->getMatrix();
			osg::Matrixd tr;
			tr.setTrans(thiz->getTranslation());
			t->setMatrix(mat*tr);
			//std::cout<<"平移信息：：：：：：：：：：：：：："<<t->getMatrix().getTrans().x()<<std::endl;
			//std::cout<<"平移信息：：：：：：：：：：：：：："<<t->getMatrix().getTrans().y()<<std::endl;
			//std::cout<<"平移信息：：：：：：：：：：：：：："<<t->getMatrix().getTrans().z()<<std::endl;
			this->thiz->setIsMAtrixForm(false);
		}

		if(t->getName() == thiz->getMatrixFormNodename() && thiz->getisMatrixRotation())
		{
			osg::Matrixd mat=t->getMatrix();
			osg::Matrixd tr;
			osg::Quat quat;
			quat.makeRotate(thiz->getAxis(),thiz->getRotationDirection());
			tr.setRotate(quat);
			thiz->setisMatrixRotation(false);
		}
		/*if(t->getName()=="2515238807" && distance_07 <max_distance)
		{
			osg::Matrixd mat=t->getMatrix();
			osg::Matrixd tr;
			distance_07++;
			tr.setTrans(osg::Vec3f(0,step,0));
			t->setMatrix(mat*tr);
		}else if(t->getName() == "2515238806" && distance_06<max_distance)
		{
			osg::Matrixd mat=t->getMatrix();
			osg::Matrixd tr;
			distance_06++;
			tr.setTrans(osg::Vec3f(step,0,0));
			t->setMatrix(mat*tr);

		}else if(t->getName() == "2515238805" && distance_05<max_distance)
		{
			osg::Matrixd mat=t->getMatrix();
			osg::Matrixd tr;
			distance_05++;
			tr.setTrans(osg::Vec3f(step,0,0));
			t->setMatrix(mat*tr);

		}else if(t->getName()=="2515238804" && distance_04<max_distance)
		{
			osg::Matrixd mat=t->getMatrix();
			osg::Matrixd tr;
			distance_04++;
			tr.setTrans(osg::Vec3f(-step,0,0));
			t->setMatrix(mat*tr);
		}else if(t->getName() == "2515238803" && distance_03<max_distance)
		{
			osg::Matrixd mat=t->getMatrix();
			osg::Matrixd tr;
			distance_03++;
			tr.setTrans(osg::Vec3f(0,0,-step));
			t->setMatrix(mat*tr);
		}else if (t->getName() == "2515238802" && distance_02<max_distance)
		{
			osg::Matrixd mat=t->getMatrix();
			osg::Matrixd tr;
			distance_02++;
			tr.setTrans(osg::Vec3f(0,0,-step));
			t->setMatrix(mat*tr);

		}else if(t->getName()=="2515238801" && distance_01<max_distance)
		{
			osg::Matrixd mat=t->getMatrix();
			osg::Matrixd tr;
			distance_01++;
			tr.setTrans(osg::Vec3f(0,-step,0));
			t->setMatrix(mat*tr);

		}else if(t->getName()=="2515238800" && distance_00 <max_distance)
		{
			osg::Matrixd mat=t->getMatrix();
			osg::Matrixd tr;
			distance_00++;
			tr.setTrans(osg::Vec3f(0,0,step));
			t->setMatrix(mat*tr);
		}else if(t->getName()=="251523880-" && distance_0_ <max_distance)
		{
			osg::Matrixd mat=t->getMatrix();
			osg::Matrixd tr;
			distance_0_++;
			tr.setTrans(osg::Vec3f(-step,0,0));
			t->setMatrix(mat*tr);
		}*/
		
	}
	traverse(node,nv);

}

void AppEngineClient::MatrixTransformExtractor::apply(osg::Geode& geode)
{
	for(unsigned int i=0;i<geode.getNumParents();i++)
		{
			osg::MatrixTransform* mf=dynamic_cast<osg::MatrixTransform* >(geode.getParent(i));
			if(mf)
			{
				mf->setUpdateCallback(new TransfromCallback(thiz));
				//cout<<"~~~~~~~~~~~~~执行否？"<<endl;
			}
		}
}
AppEngineClient::MatrixTransformExtractor::MatrixTransformExtractor(AppEngineClient* thiz):osg::NodeVisitor(osg::NodeVisitor::TRAVERSE_ACTIVE_CHILDREN),thiz(thiz)
{
}