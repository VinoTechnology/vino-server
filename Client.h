// 客户端类头文件
// author：胡山峰
// date：2013-8-29

#ifndef _CLIENT_H
#define _CLIENT_H

#include "Global.h"
#include "Manipulator.h"
#include "ScreenQuad.h"
#include "PredictionCallback.h"
#include "Message.h"
#include "TouchEventBuffer.h"
#include "RemoteFirstPersonManipulator.h"
#include "ServerTask.h"


extern enum DataType;
class Compressor;
class Manipulator;
class TouchEventBuffer;
class ViewpointMgrTask;
class MessageQueue;

class MoveEarthySkyWithEyePointTransform : public osg::Transform
{
public:

	virtual bool computeLocalToWorldMatrix(osg::Matrix& matrix,osg::NodeVisitor* nv) const;
	

	virtual bool computeWorldToLocalMatrix(osg::Matrix& matrix,osg::NodeVisitor* nv) const;
	
};
///服务器端维护的客户端抽象结构体
class Client {
public:
		Client(ViewpointMgrTask* vmt);
		//Client();
		virtual ~Client();
		//2014_8_4
		void setMessageQueue(MessageQueue* mq);//管理消息队列
		void UpdatePreViewMatrix();
		void createPredictionCamera(osg::Node* node);
		bool isTimeForPrediction();
		void setPredictionToggle(bool tag);
		void addClientsToggleToMainCamera(osg::ref_ptr<osg::Group> SceneGroup);
		void setLightBoundingBox(osg::Node* node);
		void sentOnePacket( 
			DataType dataType, 
			unsigned int cLen, 
			unsigned char* cBuf, 
			unsigned int dsLen, 
			unsigned int ddLen,
			char* dBuf,
			osg::Matrixf vp);
		void putInt(unsigned char* data, const unsigned int& val);
	    osg::Matrixf getPredInvMVP();
		void setUpCompressor(Resolution& r);
		osg::ref_ptr<osg::Camera> getColorCamera();
		bool isNiceConnect();
		
		//void calPredictionconfig();
		string id2stirng();
		osg::Program* createProgram(const std::string vert, const std::string frag);
		// --------构造时初始化---------
		tcp_Socket *_socket;
		io_service *_service;

		size_t _client_id;// 初始化的ID
		
		//size_t _read_buffer_len, _write_buffer_len;
		//unsigned char *_read_buffer;
		//unsigned char *_write_buffer;

		double _pred_period;

		double _frame_time;

		double _trans_time;

		//Manipulator * _manipulator;///控制器类

		//RemoteFirstPersonManipulator* _rfpm;

		//2014_7_7
		ManipulatorInterface* _mi;//该变量用于控制交互模式，该类型为抽象类，有三种实现方式，分别对应三种交互方式            20151031杜绍敏加的注释
		InteractionType _it;

		TouchEventBuffer* _touchBuffer;///touchBuffer
		Camera _initial_camera;//初始化视点位置

		Perspective _perspective, _pred_perspective;//透视投影
		osg::Matrixf _proj_matrix, _pred_proj_matrix;
		osg::Matrixf   _predViewMatrix;
		Resolution _resolution, _pred_resolution,_upsResolution;//视口
		Compressor* _compressor;

		// 视图矩阵
		// osg::Matrixd _view_matrix, _pred_view_matrix;

		// 颜色、深度和边图像
		osg::ref_ptr<osg::Image> _colorImage;
		osg::ref_ptr<osg::Image> _edgeImage;
		osg::ref_ptr<osg::Texture2D> _depthTex;
		osg::Timer_t _lastPredictionTime;
		osg::Timer_t _baseTime;
		// 颜色、深度和边相机
		osg::ref_ptr<osg::Camera> _colorCam;
		osg::ref_ptr<osg::Camera> _depthCam;
		osg::ref_ptr<osg::Camera> _edgeCam;

		// 场景图开关节点，下面挂载三个相机，预测时机到达时打开开关，渲染参考帧图像和深度图
		// 然后进行边检测
		osg::ref_ptr<osg::Switch>		toggle;
		
		string DATAPATH;
		bool ishaveCam;
		double _predictionInterval;
		double _averageFrameTime;
		double _isDataProcessed;
		double _interval;
		//bool _isPerspective;
		bool _isInitial;
		bool _isAdd;
		bool _isfirstRequest;
		bool _isNiceconnect;
		bool _isRunning;
		bool _isDied;
		ViewpointMgrTask* _vmt;
		MessageQueue* mq;//2014_8_4

		//2014_8_16
		void setTranslation(osg::Vec3f vec);
		osg::Vec3f getTranslation();

		void setIsMAtrixForm(bool bs);
		bool getIsMatrixForm();

		void setRotationAxis(osg::Vec3f vec);
		osg::Vec3f getAxis();

		void setRotationDirection(osg::Vec3f vec);
		osg::Vec3f getRotationDirection();

		void setMatrixFormNodename(std::string name);
		std::string getMatrixFormNodename();

		void setisMatrixRotation(bool bs);
		bool getisMatrixRotation();
private:
		osg::Vec3f tran;
		osg::Vec3f axis;
		osg::Vec3f direction;
		std::string nodeName;
		bool isMatrixForm;   //平移
		bool isMatrixRotation; //旋转
};
#endif