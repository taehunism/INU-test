#include "sub_advanced_test_ros.h"

using namespace std;
using namespace ros;
using namespace ros_lecture;

SubAdvancedTestNode::SubAdvancedTestNode()
{
  

  //subRectArray_ = nh_.subscribe(strTpNameRectInfo_, 1, &SubAdvancedTestNode::currRectArrayCbLoop, this);

  subRectArray_ = nh_.subscribe("/pub_advanced_test/rect_array", 1, &SubAdvancedTestNode::currRectArrayCbLoop, this); // this <- reference myself
}

SubAdvancedTestNode::~SubAdvancedTestNode()
{
}

void SubAdvancedTestNode::currRectArrayCbLoop(const RectArray::ConstPtr& msgRaw)
{
  msgRectArray_ = *msgRaw;

  vecRectArray_.clear();
  RectArray rectArrayTemp;
  rectArrayTemp.bDetect = msgRectArray_.bDetect;
  rectArrayTemp.nStatus = msgRectArray_.nStatus;
  rectArrayTemp.vecRectArray.clear();
  for (auto i = 0u; i < msgRectArray_.vecRectArray.size(); i++)
  {
    rectArrayTemp.vecRectArray.push_back(msgRectArray_.vecRectArray[i]);
  }
  vecRectArray_.push_back(rectArrayTemp);
  bRectArraybLoop = true;
}

void SubAdvancedTestNode::MainLoop()
{
  SubAdvancedTestFunc();
}

void SubAdvancedTestNode::SubAdvancedTestFunc()
{
  if ((bRectArraybLoop) && ((int)(vecRectArray_.size()) > 0))
  {
    // for debugging
    ROS_INFO(" ");
    ROS_INFO("vecRectArray:bDetect:(%d)", (int)(vecRectArray_[0].bDetect));
    ROS_INFO("vecRectArray:nStatus:(%d)", vecRectArray_[0].nStatus);

    for (auto i = 0u; i < vecRectArray_[0].vecRectArray.size(); i++)
    {
      ROS_INFO("vecRectArray:vectRectInfo[%d].nNum:(%d)", i, vecRectArray_[0].vecRectArray[i].nNum);
      ROS_INFO("vecRectArray:vectRectInfo[%d].fXlt:(%.4f)", i, vecRectArray_[0].vecRectArray[i].fXlt);
      ROS_INFO("vecRectArray:vectRectInfo[%d].fYlt:(%.4f)", i, vecRectArray_[0].vecRectArray[i].fYlt);
      ROS_INFO("vecRectArray:vectRectInfo[%d].fWidth:(%.4f)", i, vecRectArray_[0].vecRectArray[i].fWidth);
      ROS_INFO("vecRectArray:vectRectInfo[%d].fHeight:(%.4f)", i, vecRectArray_[0].vecRectArray[i].fHeight);
      ROS_INFO("vecRectArray:vectRectInfo[%d].fScore:(%.4f)", i, vecRectArray_[0].vecRectArray[i].fScore);
      ROS_INFO("HI~ I'M TAEHUN!  ROS_INFO is cout of cpp and printf of c and print of python!");
    }
    bRectArraybLoop = false;
  }
}

// // reading rosparams
// bool SubAdvancedTestNode::ReadRosParams()
// {
//   try
//   {
//     NodeHandle nh("");
//     ReadRosParam(nh, "/message/rect_info/name", strTpNameRectInfo_);
//   }
//   catch (RosParamNotFoundException& ex)
//   {
//     ROS_ERROR("Failed to read param at key \"%s\"", ex.key.c_str());
//     return false;
//   }

//   return true;
// }
// void SubAdvancedTestNode::ReadRosParam(ros::NodeHandle& nh, const string& key, float& val)
// {
//   if (!nh.hasParam(key))
//     throw RosParamNotFoundException(key);
//   nh.getParam(key, val);
// }
// void SubAdvancedTestNode::ReadRosParam(ros::NodeHandle& nh, const string& key, double& val)
// {
//   if (!nh.hasParam(key))
//     throw RosParamNotFoundException(key);
//   nh.getParam(key, val);
// }
// void SubAdvancedTestNode::ReadRosParam(ros::NodeHandle& nh, const string& key, bool& val)
// {
//   if (!nh.hasParam(key))
//     throw RosParamNotFoundException(key);
//   nh.getParam(key, val);
// }
// void SubAdvancedTestNode::ReadRosParam(ros::NodeHandle& nh, const string& key, int32_t& val)
// {
//   if (!nh.hasParam(key))
//     throw RosParamNotFoundException(key);
//   nh.getParam(key, val);
// }
// void SubAdvancedTestNode::ReadRosParam(ros::NodeHandle& nh, const string& key, string& val)
// {
//   if (!nh.hasParam(key))
//     throw RosParamNotFoundException(key);
//   nh.getParam(key, val);
//   if (val.empty())
//     throw RosParamNotFoundException(key);
// }