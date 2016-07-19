#include <Windows.h>
#include <osg/Node>
#include <osg/MatrixTransform>
#include "SceneMgr.h"
#include <string>

bool Scene_Mgr::loadMode=false;
bool Scene_Mgr::loadStatus=false;
Scene_Mgr* Scene_Mgr::_scene_mgr=NULL;
MapScene Scene_Mgr::_sceneMap;
Scene_Mgr::Scene_Mgr()
{

}
osg::ref_ptr<osg::Node> Scene_Mgr::getSceneByName(string name)
{
	MapScene::iterator it= _sceneMap.find(name);
	osg::ref_ptr<osg::Node> result=NULL;
	if(it!=_sceneMap.end())       ///2015_4_21�޸�
	{
		result=it->second;
	}
	return result;
}
Scene_Mgr* Scene_Mgr::instance()
{
	LoadScene();
	if(_scene_mgr==NULL)
		_scene_mgr=new Scene_Mgr;

	return _scene_mgr;
}
bool Scene_Mgr::LoadScene()
{
	if(!loadStatus)
	{
		cout<<"����������...."<<endl;
		//osg::ref_ptr<osg::Node> node_paris=osgDB::readNodeFile("E:\\WorkStation\\OpenSceneGraph-Data-3.0.0\\paris_no_tree.osg");
		//std::cout<<"���賡��������"<<node_paris->getBound().center().x()<<"   "<<node_paris->getBound().center().y()<<"    "<<node_paris->getBound().center().z()<<endl;//��һ���Ǽӵ�
		//osg::ref_ptr<osg::Node> node_engine=osgDB::readNodeFile("E:\\WorkStation\\OpenSceneGraph-Data-3.0.0\\engine2.osg");
		
		//���������Ƕ�����12112236�ӵ�
		//osg::ref_ptr<osg::Node> node_car=osgDB::readNodeFile("E:\\WorkStation\\OpenSceneGraph-Data-3.0.0\\car.osg");
		//std::cout<<"����������"<<node_car->getBound().center().x()<<"   "<<node_car->getBound().center().y()<<"    "<<node_car->getBound().center().z()<<endl;//��һ���Ǽӵ�
		//std::cout<<"�����İ뾶"<<node_car->getBound().radius()<<endl;

		//�������ӵ�
		//std::cout<<"����������������"<<node_engine->getBound().center().x()<<"   "<<node_engine->getBound().center().y()<<"    "<<node_engine->getBound().center().z()<<endl;
		//std::cout<<"�����������İ뾶"<<node_engine->getBound().radius()<<endl;
		
		//osg::MatrixTransform * mt=new osg::MatrixTransform;
		//mt->setMatrix(osg::Matrix::translate(-12128.1,7189.28,1211.33)* osg::Matrix::scale(0.01,0.01,0.01));
		//mt->addChild(node_engine);//ִ��ƽ��
		//std::cout<<"����������������"<<mt->getBound().center().x()<<"   "<<mt->getBound().center().y()<<"    "<<mt->getBound().center().z()<<endl;
		//std::cout<<"�����������İ뾶"<<mt->getBound().radius()<<endl;
		

		//#############################################
		//osg::ref_ptr<osg::Node> node_cessna=osgDB::readNodeFile("E:\\WorkStation\\OpenSceneGraph-Data-3.0.0\\cessna.osg");
		//std::cout<<"�ɻ�����������"<<node_cessna->getBound().center().x()<<"   "<<node_cessna->getBound().center().y()<<"    "<<node_cessna->getBound().center().z()<<endl;//�������ӵ�
		//std::cout<<"�ɻ������İ뾶"<<node_cessna->getBound().radius()<<endl;//�������ӵ�
		//osg::ref_ptr<osg::Node> node_armadillo=osgDB::readNodeFile("E:\\WorkStation\\OpenSceneGraph-Data-3.0.0\\armadillo.ply");
		//std::cout<<"��ɽ�׳���������"<<node_armadillo->getBound().center().x()<<"   "<<node_armadillo->getBound().center().y()<<"    "<<node_armadillo->getBound().center().z()<<endl;//�������ӵ�
		//osg::ref_ptr<osg::Node> node_sky=osgDB::readNodeFile("E:\\WorkStation\\OpenSceneGraph-Data-3.0.0\\sky.osgt");
		//std::cout<<"��ճ���������"<<node_sky->getBound().center().x()<<"   "<<node_sky->getBound().center().y()<<"    "<<node_sky->getBound().center().z()<<endl;//�������ӵ�
		osg::ref_ptr<osg::Node> node_campus = osgDB::readNodeFile("D:\\edushi\\gsModel\\gsCampusFinal.osg"); //20140917
		//std::cout<<"����Ӫ������"<<node_campus->getBound().center().x()<<"   "<<node_campus->getBound().center().y()<<"    "<<node_campus->getBound().center().z()<<endl;//�������ӵ�
		//osg::ref_ptr<osg::Node> node_chair= osgDB::readNodeFile("E:\\WorkStation\\OpenSceneGraph-Data-3.0.0\\yizi.osg");//20150613
		//std::cout<<"���ӵ�����"<<node_chair->getBound().center().x()<<"   "<<node_chair->getBound().center().y()<<"    "<<node_chair->getBound().center().z()<<endl;//�������ӵ�
		//std::cout<<"���ӵİ뾶"<<node_chair->getBound().radius()<<endl;
		//_sceneMap.insert(pair<string,osg::ref_ptr<osg::Node>>("paris",node_paris));
		//_sceneMap.insert(pair<string,osg::ref_ptr<osg::Node>>("engine",node_engine));//ԭ�ȴ���@20150904
		//_sceneMap.insert(pair<string,osg::ref_ptr<osg::Node>>("engine",mt));//�޸�@20150904
		//_sceneMap.insert(pair<string,osg::ref_ptr<osg::Node>>("cessna",node_cessna));
		//_sceneMap.insert(pair<string,osg::ref_ptr<osg::Node>>("armadillo",node_armadillo));
		//_sceneMap.insert(pair<string,osg::ref_ptr<osg::Node>>("sky",node_sky));
		_sceneMap.insert(pair<string, osg::ref_ptr<osg::Node> >("campus", node_campus));//20140917
		//_sceneMap.insert(pair<string,osg::ref_ptr<osg::Node>>("chair",node_chair));//20150613

		//_sceneMap.insert(pair<string,osg::ref_ptr<osg::Node>>("car",node_car));//201512112227�������ӵ�
		
		loadStatus=true;
				//std::cout<<"����������������"<<mt->getBound().center().x()<<"   "<<mt->getBound().center().y()<<"    "<<mt->getBound().center().z()<<endl;
		//std::cout<<"�����������İ뾶"<<mt->getBound().radius()<<endl;
				//std::cout<<"����������������"<<node_engine->getBound().center().x()<<"   "<<node_engine->getBound().center().y()<<"    "<<node_engine->getBound().center().z()<<endl;
		//std::cout<<"�����������İ뾶"<<node_engine->getBound().radius()<<endl;
		cout<<"�����������...."<<endl;
	}

	return loadStatus;
}
bool Scene_Mgr::getLoadStatus()
{
	return loadStatus;
}