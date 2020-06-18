1.use Qt Creator 4.10.0, Qt Creator 4.11.1(Based on Qt5.14.1) is ok too;

2.Ubuntu 18.10, ubuntu19.10 is ok too;

3.Tobii Pro Eye Tracker Manager
this web "https://www.tobiipro.com/zh/learn-and-support/downloads-pro/";
you can search "Tobii Pro Eye Tracker Manager";
then download "Tobii Pro Eye Tracker Manager for Linux 2.1.2";
you can use "dpkg -i TobiiProEyeTrackerManager-2.1.0.deb" to install;
If you want to use the software of "TobiiProEyeTrackerManager", you must install two dependency packages.
the tow packages: "tobii_config_0.1.6.111_amd64.deb", and "tobiiusbservice_l64U14_2.1.5-28fd4a.deb", the file is in "https://github.com/intfreedom/Tobii-Eye-Tracker-Tobii-4C/tree/master/tobii_eye_tracker_linux_installer-master"

4.可以利用tobii的头文件和动态链接库来读取眼动仪的数据，具体要调用的函数参考头文件；必须把头文件放到工程目录中，并且添加动态链接库到项目；
4.1 Download the file: tobii.h, tobii_advanced.h, tobii_config.h, tobii_licensing.h,tobii_streams.h, tobii_wearable.h, and libtobii_stream_engine.so.you can download from here: https://github.com/intfreedom/Tobii-Eye-Tracker-Tobii-4C/tree/master/GUI/Demo/tobii, https://github.com/intfreedom/Tobii-Eye-Tracker-Tobii-4C/tree/master/tobii_eye_tracker_linux_installer-master/lib/lib/x64
4.2使用Qt新建一个工程，把tobii的头文件，动态链接库添加至工程；File->New File or Project...(Default Settings only)
4.3添加头文件Right-click the project name->Add  Existing Directory..., you must add all the "head file";For example: "tobii.h,tobii_advanced.h, tobii_config.h, tobii_licensing.h,tobii_streams.h, tobii_wearable.h";
4.4 添加动态链接库：Right-click the project name->Add  Library...->Internal library;then, select the file: "libtobii_stream_engine.so"

It allows to install the drivers and development libraries to operate devices compatible with IS4 (Tobii 4C).
Use the Tobii 4C and corresponding API files to obtain the eye movement data needed for the study;
