#include <iostream>
#include "GeometricRecognizer.h"
#include "PathWriter.h"

#include "HelloWorldScene.h"

#include "json/rapidjson.h"
#include "json/document.h"
#include "json/writer.h"
#include "json/stringbuffer.h"

#include "renderer/CCGLProgramStateCache.h"

//#include "json/filestream.h"
//#include "json/prettywriter.h"

using namespace rapidjson; // 命名空间

using namespace std;
using namespace DollarRecognizer;

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
   auto closeItem = MenuItemImage::create(
                                          "CloseNormal.png",
                                          "CloseSelected.png",
                                          CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

   closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                               origin.y + closeItem->getContentSize().height/2));

   // create menu, it's an autorelease object
   auto menu = Menu::create(closeItem, NULL);
   menu->setPosition(Vec2::ZERO);
   this->addChild(menu, 1);
    
   auto cleanItem = MenuItemImage::create(
                                          "CloseNormal.png",
                                          "CloseSelected.png",
                                          CC_CALLBACK_1(HelloWorld::menuCleanCallback, this));

   cleanItem->setPosition(Vec2(origin.x + visibleSize.width - cleanItem->getContentSize().width/2 - 60 ,
                               origin.y + cleanItem->getContentSize().height/2));

   // create menu, it's an autorelease object
   auto cleanMenu = Menu::create(cleanItem, NULL);
   cleanMenu->setPosition(Vec2::ZERO);
   this->addChild(cleanMenu, 1);
    
#ifdef MY_TEST
//    cocos2d::Data d = FileUtils::getInstance()->getDataFromFile("/Users/admin/Documents/workspace/TestScript/ui/main.lua");
//    char* data = (char*)d.getBytes();
//    int dataLength = (int)d.getSize();
//
//    int b1=data[0]&0xFF;
//    int b2=data[1]&0xFF;
//    int b3=data[2]&0xFF;
//    int b4=data[3]&0xFF;
//    int flag = (b1<<24)|(b2<<16)|(b3<<8)|(b4<<0);
//
//    char* temp=new char[dataLength];
//    memset(temp, '\0', dataLength);
//    memcpy(temp,data+4,dataLength);
//    for(int i = dataLength - 5; i > 0; i--){
//        temp[i] ^= temp[i - 1];
//    }
//    temp[0] ^= -88;//密码
//    printf("%s", temp);
#endif
    //手势识别
//   auto s = Director::getInstance()->getWinSize();
//
//   auto listener = EventListenerTouchAllAtOnce::create();
//   listener->onTouchesBegan = CC_CALLBACK_2(HelloWorld::onTouchesBegan, this);
//   listener->onTouchesMoved = CC_CALLBACK_2(HelloWorld::onTouchesMoved, this);
//   listener->onTouchesEnded = CC_CALLBACK_2(HelloWorld::onTouchesEnded, this);
//   _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
//
//   target = cocos2d::RenderTexture::create(s.width, s.height, Texture2D::PixelFormat::RGB888);
//   target->retain();
//   target->setPosition(Vec2(s.width/2, s.height/2));
//   this->addChild(target);
    
    
    //shader 练习
    // auto s = Director::getInstance()->getWinSize();

    // auto bg = Sprite::create("bg.png");
    // bg->setPosition(s.width*1/2, s.height/2);
    // this->addChild(bg);

    // // Left: normal sprite
    // auto left = Sprite::create("HelloWorld.png");
    // left->setPosition(s.width*1/4, s.height/2);
    // this->addChild(left);

    // auto right = Sprite::create("zhan.png");
    // addChild(right);
    // right->setPosition(s.width*3/4, s.height/2);

    // // Center: MultiTexture
    // auto _sprite = Sprite::createWithTexture(right->getTexture());
    // addChild(_sprite);
    // _sprite->setPosition(Vec2(s.width/2, s.height/2));

    // auto glprogram = GLProgram::createWithFilenames("mappiece_vert.glsl", "mappiece_frag.glsl");
    // auto glprogramstate = GLProgramState::getOrCreateWithGLProgram(glprogram);
    // _sprite->setGLProgramState(glprogramstate);

    // glprogramstate->setUniformTexture("u_texture1", left->getTexture());
    // glprogramstate->setUniformFloat("u_interpolate",0.4);

    // //gray shader
    // glprogram = GLProgram::createWithFilenames("gray_vert.glsl", "gray_frag.glsl");
    // glprogramstate = GLProgramState::getOrCreateWithGLProgram(glprogram);

    // glprogramstate->setUniformVec4("u_grayParam", Vec4(0.2f,0.3f,0.5f,1.0f));
    // //调用node节点的setGLProgramState，以后此节点渲染就会使用这个Shader了
    // bg->setGLProgramState(glprogramstate);

    // auto *pShader = GLProgramState::create(GLProgram::createWithFilenames("blur_vert.glsl", "blur_frag.glsl"));
    // pShader->setUniformVec3("u_color", Vec3(1.0, 0.0, 0.0));
    // pShader->setUniformFloat("u_line_size", 0.01);
    // pShader->applyUniforms();
    // right->setGLProgramState(pShader);
    // left->setGLProgramState(pShader);
    
//    SpriteFrameCache *frameCache = SpriteFrameCache::getInstance();
//    frameCache->addSpriteFramesWithFile("btn/btn.plist", "btn/btn.png");
//    //性能测试ABAB
//    for (int i=0; i<100; i++) {
//        auto closeItem = MenuItemImage::create(
//                                               "",
//                                               "",
//                                               CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
//
//        closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
//                                    origin.y + closeItem->getContentSize().height/2));
//        // create menu, it's an autorelease object
//        closeItem->setNormalSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("btn.png"));
//        closeItem->setSelectedSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("btn_on.png"));
//        auto menu = Menu::create(closeItem, NULL);
//        menu->setPosition(Vec2(-visibleSize.width/2, visibleSize.height/2));
//        this->addChild(menu, 1);
//
//        auto baoji = Sprite::createWithSpriteFrameName("baoji.png");
//        baoji->setPosition(Vec2(55, 19));
//        closeItem->addChild(baoji);
//    }
    
    //性能测试ABAB
    for (int i=0; i<100; i++) {
        auto closeItem = MenuItemImage::create(
                                               "btn/1/btn.png",
                                               "btn/1/btn_on.png",
                                               CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

        closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                    origin.y + closeItem->getContentSize().height/2));
        closeItem->setGlobalZOrder(1);
        // create menu, it's an autorelease object
        auto menu = Menu::create(closeItem, NULL);
        menu->setPosition(Vec2(-visibleSize.width/2, visibleSize.height/2));
        this->addChild(menu, 1);

        auto baoji = Sprite::create("btn/1/baoji.png");
        baoji->setPosition(Vec2(55, 19));
        baoji->setGlobalZOrder(1);
//        baoji->setLocalZOrder(1);
        closeItem->addChild(baoji);
    }
    CCLOG("Global Z Order %d", this->getGlobalZOrder());

    return true;
}

//置灰接口
void HelloWorld::grayNode(Node* node)
{
    //对应xxCache的运用，先成缓存中找，不需要每次都重新创建
    GLProgram* program = GLProgramCache::getInstance()->getGLProgram("MyGrayShader");
    if(nullptr == program)
    {
        //本地磁盘加载shader创建program,还一种字符串的形式效率要高createWithByteArrays()
        program = GLProgram::createWithFilenames("gray_vert.glsl", "gray_frag.glsl");
        //将GLProgram对象缓存到Cache中
        GLProgramCache::getInstance()->addGLProgram(program, "MyGrayShader");
    }
    //通过program创建programState,用它来设置上面自定义的Uniform变量的值
    GLProgramState* programState = GLProgramState::getOrCreateWithGLProgram(program);
    programState->setUniformVec4("u_grayParam", Vec4(0.2f,0.3f,0.5f,1.0f));
    //调用node节点的setGLProgramState，以后此节点渲染就会使用这个Shader了
    node->setGLProgramState(programState);
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::menuCleanCallback(Ref* pSender)
{
//    CCLOG("_brushs clear cnt = %ld", _brushs.size());
    target->clear(0, 0, 0, 0);
//    _brushs.clear();
    std::vector <cocos2d::Sprite*>().swap(_brushs);
//    CCLOG("_brushs cnt = %ld", _brushs.size());
}

void HelloWorld::onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event)
{
    auto touch = touches[0];
    auto start = touch->getLocation();
//    CCLOG("x = %f, y = %f", start.x, start.y);
}

void HelloWorld::onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event)
{
    auto touch = touches[0];
    auto start = touch->getLocation();
    auto end = touch->getPreviousLocation();
    _path.push_back(start);
    // begin drawing to the render texture
    target->begin();
    
    // for extra points, we'll draw this smoothly from the last position and vary the sprite's
    // scale/rotation/offset
    float distance = start.getDistance(end);
    if (distance > 1)
    {
        int d = (int)distance;
//        _brushs.clear();
        std::vector <cocos2d::Sprite*>().swap(_brushs);
        for(int i = 0; i < d; ++i)
        {
            Sprite * sprite = Sprite::create("line_texture.png");
//            sprite->setColor(Color3B::RED);
//            sprite->setOpacity(20);
            _brushs.push_back(sprite);
        }
        for (int i = 0; i < d; i++)
        {
            float difx = end.x - start.x;
            float dify = end.y - start.y;
            float delta = (float)i / distance;
            _brushs.at(i)->setPosition(Vec2(start.x + (difx * delta), start.y + (dify * delta)));
            _brushs.at(i)->setRotation(rand() % 360);
            float r = (float)(rand() % 50 / 50.f) + 0.25f;
            _brushs.at(i)->setScale(r);
            /*_brush->setColor(Color3B(CCRANDOM_0_1() * 127 + 128, 255, 255));*/
            // Use CCRANDOM_0_1() will cause error when loading libtests.so on android, I don't know why.
            _brushs.at(i)->setColor(Color3B(rand() % 127 + 128, 255, 255));
            // Call visit to draw the brush, don't call draw..
            _brushs.at(i)->visit();
        }
    }
    
    // finish drawing and return context back to the screen
    target->end();
}

void HelloWorld::onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event)
{
    std::string str = FileUtils::getInstance()->getStringFromFile("templates/shape.json");
    std::vector<std::string> path_vec;
    rapidjson::Document d;
    d.Parse<rapidjson::kParseDefaultFlags>(str.c_str());
    if (d.HasParseError()) {
//        CCLOG("GetParseError %s\n",d.GetParseError());
        return;
    }
    if (d.IsObject()) {
        if (d.HasMember("gestures")) {
            for (int i = 0; i < d["gestures"].Size(); i++) {
                path_vec.push_back(StringUtils::format("templates/%s.json",d["gestures"][i].GetString()));
            }
        }
    }
    
    GeometricRecognizer g;
    std::vector<string> gesturesList;
    for (int i=0; i<path_vec.size(); i++)
    {
        Path2D path;
        std::string gestureName = "Circle";
        std::string str = FileUtils::getInstance()->getStringFromFile(path_vec.at(i));
        rapidjson::Document d;
        d.Parse<rapidjson::kParseDefaultFlags>(str.c_str());
        if (d.HasParseError()) {
            CCLOG("GetParseError %s\n",d.GetParseError());
            return;
        }
        if (d.IsObject()) {
            if (d.HasMember("name")) {
                gestureName = d["name"].GetString();
            }
            if (d.HasMember("points")) {
                for (int i = 0; i < d["points"].Size(); i++) {
                    if (d["points"][i].IsArray()) {
                        path.push_back(Point2D(d["points"][i][0].GetInt(), d["points"][i][1].GetInt()));
                    }
                }
            }
        }
        g.addTemplate(gestureName, path);
        gesturesList.push_back(gestureName);
    }
    g.activateTemplates(gesturesList);

    Path2D path;
    float height = cocos2d::Director::getInstance()->getWinSize().height;
    for (int i=0; i<_path.size(); i++) {
        float x = _path.at(i).x;
        float y = height-_path.at(i).y;
        path.push_back(Point2D(x,y));
    }

    if (path.size() <= 20) {
        CCLOG("PATH_SIZE = %d", path.size());
        return;
    }

    RecognitionResult r=g.recognize(path);
    cout << "Recognized gesture: " << r.name << endl;
    cout << "1$ Score:" << r.score << endl;

    RecognitionResult rp=g.recognize(path, "protractor");
    cout << "Recognized gesture: " << rp.name << endl;
    cout << "Cosine Score:" << rp.score << endl;
    
//    _path.clear();
    std::vector<cocos2d::Vec2>().swap(_path);
}
