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
	if(it!=_sceneMap.end())       ///2015_4_21修改
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
		cout<<"场景加载中...."<<endl;
		//osg::ref_ptr<osg::Node> node_paris=osgDB::readNodeFile("E:\\WorkStation\\OpenSceneGraph-Data-3.0.0\\paris_no_tree.osg");
		//std::cout<<"巴黎场景的中心"<<node_paris->getBound().center().x()<<"   "<<node_paris->getBound().center().y()<<"    "<<node_paris->getBound().center().z()<<endl;//这一行是加的
		//osg::ref_ptr<osg::Node> node_engine=osgDB::readNodeFile("E:\\WorkStation\\OpenSceneGraph-Data-3.0.0\\engine2.osg");
		
		//以下两行是杜绍敏12112236加的
		//osg::ref_ptr<osg::Node> node_car=osgDB::readNodeFile("E:\\WorkStation\\OpenSceneGraph-Data-3.0.0\\car.osg");
		//std::cout<<"汽车的中心"<<node_car->getBound().center().x()<<"   "<<node_car->getBound().center().y()<<"    "<<node_car->getBound().center().z()<<endl;//这一行是加的
		//std::cout<<"汽车的半径"<<node_car->getBound().radius()<<endl;

		//杜绍敏加的
		//std::cout<<"发动机场景的中心"<<node_engine->getBound().center().x()<<"   "<<node_engine->getBound().center().y()<<"    "<<node_engine->getBound().center().z()<<endl;
		//std::cout<<"发动机场景的半径"<<node_engine->getBound().radius()<<endl;
		
		//osg::MatrixTransform * mt=new osg::MatrixTransform;
		//mt->setMatrix(osg::Matrix::translate(-12128.1,7189.28,1211.33)* osg::Matrix::scale(0.01,0.01,0.01));
		//mt->addChild(node_engine);//执行平移
		//std::cout<<"发动机场景的中心"<<mt->getBound().center().x()<<"   "<<mt->getBound().center().y()<<"    "<<mt->getBound().center().z()<<endl;
		//std::cout<<"发动机场景的半径"<<mt->getBound().radius()<<endl;
		

		//#############################################
		//osg::ref_ptr<osg::Node> node_cessna=osgDB::readNodeFile("E:\\WorkStation\\OpenSceneGraph-Data-3.0.0\\cessna.osg");
		//std::cout<<"飞机场景的中心"<<node_cessna->getBound().center().x()<<"   "<<node_cessna->getBound().center().y()<<"    "<<node_cessna->getBound().center().z()<<endl;//杜绍敏加的
		//std::cout<<"飞机场景的半径"<<node_cessna->getBound().radius()<<endl;//杜绍敏加的
		//osg::ref_ptr<osg::Node> node_armadillo=osgDB::readNodeFile("E:\\WorkStation\\OpenSceneGraph-Data-3.0.0\\armadillo.ply");
		//std::cout<<"穿山甲场景的中心"<<node_armadillo->getBound().center().x()<<"   "<<node_armadillo->getBound().center().y()<<"    "<<node_armadillo->getBound().center().z()<<endl;//杜绍敏加的
		//osg::ref_ptr<osg::Node> node_sky=osgDB::readNodeFile("E:\\WorkStation\\OpenSceneGraph-Data-3.0.0\\sky.osgt");
		//std::cout<<"天空场景的中心"<<node_sky->getBound().center().x()<<"   "<<node_sky->getBound().center().y()<<"    "<<node_sky->getBound().center().z()<<endl;//杜绍敏加的
		osg::ref_ptr<osg::Node> node_campus = osgDB::readNodeFile("D:\\edushi\\gsModel\\gsCampusFinal.osg"); //20140917
		//std::cout<<"夏令营的中心"<<node_campus->getBound().center().x()<<"   "<<node_campus->getBound().center().y()<<"    "<<node_campus->getBound().center().z()<<endl;//杜绍敏加的
		//osg::ref_ptr<osg::Node> node_chair= osgDB::readNodeFile("E:\\WorkStation\\OpenSceneGraph-Data-3.0.0\\yizi.osg");//20150613
		//std::cout<<"椅子的中心"<<node_chair->getBound().center().x()<<"   "<<node_chair->getBound().center().y()<<"    "<<node_chair->getBound().center().z()<<endl;//杜绍敏加的
		//std::cout<<"椅子的半径"<<node_chair->getBound().radius()<<endl;
		//_sceneMap.insert(pair<string,osg::ref_ptr<osg::Node>>("paris",node_paris));
		//_sceneMap.insert(pair<string,osg::ref_ptr<osg::Node>>("engine",node_engine));//原先代码@20150904
		//_sceneMap.insert(pair<string,osg::ref_ptr<osg::Node>>("engine",mt));//修改@20150904
		//_sceneMap.insert(pair<string,osg::ref_ptr<osg::Node>>("cessna",node_cessna));
		//_sceneMap.insert(pair<string,osg::ref_ptr<osg::Node>>("armadillo",node_armadillo));
		//_sceneMap.insert(pair<string,osg::ref_ptr<osg::Node>>("sky",node_sky));
		_sceneMap.insert(pair<string, osg::ref_ptr<osg::Node> >("campus", node_campus));//20140917
		//_sceneMap.insert(pair<string,osg::ref_ptr<osg::Node>>("chair",node_chair));//20150613

		//_sceneMap.insert(pair<string,osg::ref_ptr<osg::Node>>("car",node_car));//201512112227杜绍敏加的
		
		loadStatus=true;
				//std::cout<<"发动机场景的中心"<<mt->getBound().center().x()<<"   "<<mt->getBound().center().y()<<"    "<<mt->getBound().center().z()<<endl;
		//std::cout<<"发动机场景的半径"<<mt->getBound().radius()<<endl;
				//std::cout<<"发动机场景的中心"<<node_engine->getBound().center().x()<<"   "<<node_engine->getBound().center().y()<<"    "<<node_engine->getBound().center().z()<<endl;
		//std::cout<<"发动机场景的半径"<<node_engine->getBound().radius()<<endl;
		cout<<"场景加载完成...."<<endl;
	}

	return loadStatus;
}
bool Scene_Mgr::getLoadStatus()
{
	return loadStatus;
}