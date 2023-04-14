---
description: 主要包含2020-2023年在中国石油大学（华东）参与的项目
---

# 😄 主要项目情况

本科期间主要为<mark style="color:red;">**深度学习**</mark>方面项目，主要项目为以下<mark style="color:red;">**六项**</mark>

<mark style="background-color:orange;">**基于推荐算法与自然语言处理的一带一路国家汉语言论坛**</mark>&#x20;

2022年06月 - 2022年09月 <mark style="color:red;">**个人排名1/3**</mark>

基于Bag of Words和k-means ++算法对用户搜素记录进行提取和聚类，根据用户搜索关键词对用户进行分类&#x20;

使用自定义的推荐算法，为用户推荐相应的话题，并且根据用户点击等数据进行实时更新&#x20;

使用Django+Mysql+Nginx完成了后端的开发任务，并且部署到云服务器上&#x20;

相关作品获得了计算机设计大赛<mark style="color:red;">**三等奖**</mark>，互联网+创新创业大赛甘肃省<mark style="color:red;">**银奖第一名**</mark>，以<mark style="color:red;">**第一作者**</mark>发表软件著作权两项&#x20;

<mark style="background-color:orange;">**Kaggle Competition Feedback Prize - English Language Learning**</mark>&#x20;

2022年09月 - 2022年12月 <mark style="color:red;">**个人排名1/1**</mark>

使用Bag of Words和多输入输出bp-network，编写NLP推理模型baseline，获得lb=0.7188&#x20;

改用bert模型来充当解码器提取特征配合Transformer方法，提高lb=0.4776&#x20;

学习了RoBERTa和DeBERTa，使用10个DeBERTa模型进行集成学习，lb=0.4374，

独立参赛<mark style="color:red;">**solo一枚Kaggle铜牌**</mark>

<mark style="background-color:orange;">**Kaggle Competition Classify Leaves**</mark>&#x20;

2022年11月 - 2022年12月 <mark style="color:red;">**个人排名1/1**</mark>&#x20;

编写图片分类baseline，在大小相差很大的树叶数据集和鱼类数据集上分别获得了84.36%和83.3%的准确率

使用Vision transformer来进行图像分类任务，最终在两个数据集上的正确率分别提高到91.2%和97.8%

&#x20;阅读SOTA方案，使用带有注意力的backbone，更好的图像增广，集成学习等方法，提高了准确率到96.5%和99.4%

<mark style="background-color:orange;">**Kaggle Competition CowBoy Outfits Detection**</mark>&#x20;

2023年01月 - 2023年02月 <mark style="color:red;">**个人排名1/1**</mark>

直接使用yolov5进行了目标检测任务。使用yolov5-large模型，MAP=14.16&#x20;

使用欠采样样本平衡，重新训练适合样本的anchor，在backbone中增加了Swim transformer层，提高了模型MAP=34.55&#x20;

对视频文件进行了目标检测，相关链接[https://live.csdn.net/v/271877 ](https://live.csdn.net/v/271877)

<mark style="background-color:orange;">**李沐《动手学深度学习》语义分割实践与拓展**</mark>&#x20;

2023年02月 - 2023年03月 <mark style="color:red;">**个人排名1/1**</mark>

使用改进的FCN网络在Pascal2012数据集上进行语义分割，对比了是否使用辅助分类器，分别得到meanIOU=67.4与70.9。&#x20;

使用Unet使用在DRIVE数据集上进行的语义分割，得到meanIOU=80.1。&#x20;

对Unet进行改进，使用交叉熵与dice的混合损失函数，并且使用双线性插值来上采样等方法，meanIOU=81.5。&#x20;

<mark style="background-color:orange;">**基于边缘计算设备的图像分类与目标检测**</mark>&#x20;

2023年02月 - 至今  <mark style="color:red;">**个人排名1/1**</mark>

使用动态模糊使得智能车在运行过程中也可以保持对图像的分类，减少了识别时间&#x20;

修改yolov3-tiny的backbone为mobilenetv2，使用深度可分离卷积来减少参数数量&#x20;

编写openmv代码，使代码可以在边缘计算设备openArt上执行
