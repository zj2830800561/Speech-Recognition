# Speech-Recognition  

*使用百度智能云语音识别接口完成简单的语音识别：  
>接口类型：通过 REST API 的方式提供的通用的 HTTP 接口。适用于任意操作系统，任意编程语言  
>接口限制：需要上传完整的录音文件，录音文件时长不超过 60 秒  
>支持音频格式：pcm、wav、amr、m4a  
>音频编码要求：采样率 16000、8000（仅支持普通话模型），16 bit 位深，单声道  
    
详细使用方法见百度语音技术文档：https://ai.baidu.com/ai-doc/SPEECH/Vk38lxily  


*程序界面：  
![image](https://user-images.githubusercontent.com/65062606/167701052-52b367fc-2a16-4cfc-9a90-a7d540270883.png)


*类的使用：  
>audio：完成音频录制的类  
>http：完成发送POST请求、接收服务器解析结果的类  
>speech：发送录音文件进行语言识别，对返回的JSON数据进行解析返回识别文字  
  
*运行效果：  
![image](https://user-images.githubusercontent.com/65062606/167700697-ddf0a287-1384-4ad6-a876-0120225d6745.png)
