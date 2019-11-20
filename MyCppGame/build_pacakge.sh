#!/bin/bash
#就是运行下ant，然后install

cd $1

tmp1=`cat "AndroidManifest.xml" | grep "package="`
tmp2=${tmp1#*\"}
package=${tmp2%\"}

# find assets/ui -depth -empty -type d | while read line; do
#     echo "------------------发现空目录：${line}------------------" 
# done

# read -p "是否需要更新Classes目录？(y/n)" ClassesUpdate
# if [[ $ClassesUpdate == "Y" || $ClassesUpdate == "y" ]]; then
#     cd ../ROR/Classes
#     svn update
#     cd -
# fi

# read -p "是否需要更新ROR2目录？(y/n)" ROR2
# if [[ $ROR2 == "Y" || $ROR2 == "y" ]]; then
#     cd ../
#     svn update
#     cd -
# fi

# echo ""
# echo $package
# read -p "请确认包名，输入任意键继续："

# echo ""
# cat "AndroidManifest.xml" | grep "versionCode"
# read -p "请确认versionCode，输入任意键继续："

# echo ""
# vn=`cat "AndroidManifest.xml" | grep "versionName"`
# echo ${vn%\>}
# read -p "请确认versionName，输入任意键继续："

# echo ""
# sed -n '1p' assets/data/version.dat
# read -p "请确认version data, 输入任意键继续："

# echo ""
# cat "src/org/goodev/expansion/downloader/ApkExpansionDownloader.java" | grep "new XAPKFile(true"
# read -p "请确认obb版本和大小，输入任意键继续："

# echo ""
# cat "src/com/lehoo/ror/GameActivity.java" | grep "boolean wholeApk"
# read -p "请确认是否是整包，输入任意键继续："

# echo ""
# sound=`find assets/sound -name "background.mp3"`
# if [[ $sound == "" ]]; then
# 	while [[ $k != "k" && $k != "K" ]]; do
# 		read -p "sound文件中缺少background.mp3，请修复，输入任意k键继续：" k
# 	done
# fi

# echo ""
# OLD_IFS="$IFS" 
# IFS=' '
# maps=`ls assets/map`
# echo $maps
# read -p "请确认map文件，输入任意键继续："
# IFS=$OLD_IFS

# java -jar ../tool/"decrypt.jar" assets/ui > tmp
# echo ""
# cat "assets/ui/ResourceUpdate.lua" | grep "bundleId" | grep "=="
# read -p "请确认是否正确配置bundleId，输入任意键继续："

# java -jar ../tool/"encrypt.jar" assets/ui > tmp
# cd ../tool/android
# sh plistPath.sh > tmp
# sh encryption.sh > tmp
rm tmp
# cd -

echo ""
while [[ $y != "y" && $y != "Y" ]]; do
	read -p "请确认以上配置都正确，输入任意y键继续：" y
done

sh build_native.sh
ant -buildfile build2.xml
# rm /Volumes/lehoo/Sites/*.apk
# cp bin_ror/*.apk /Volumes/lehoo/Sites/

# svn status assets/data | xargs svn revert
# svn status assets/anim | xargs svn revert

adb uninstall $package
# sh ../tool/android/decryption.sh
adb install bin_ror/*.apk