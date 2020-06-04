#! /usr/bin/env python
# -*- coding: utf-8 -*-

import os.path
import sys
import demjson
import pickle
import re

expPath = "czzFileDel"

def show_params(params):
	lenIdx = len(params)
	for index in range(lenIdx):
		print "argv" + str(index) + ":" + str(sys.argv[index])

def save_obj(obj, name ):
	with open(name, 'wb') as f:
		pickle.dump(obj, f, pickle.HIGHEST_PROTOCOL)
		
def load_obj(name ):
	with open(name, 'rb') as f:
		return pickle.load(f)
		
def ReadFile(filePath):
	file_object = open(filePath,'rb')
	all_the_text = file_object.read()
	file_object.close()
	return all_the_text

def WriteFile(filePath,all_the_text):	
	file_object = open(filePath,'wb+')	
	file_object.write(all_the_text)
	file_object.close()
	
def removeFilePath(filePath):
	for root, dirs, files in os.walk(filePath, topdown=False):
		for name in files:
			os.remove(os.path.join(root, name))
		for name in dirs:
			os.rmdir(os.path.join(root, name))
			
def get_FileModifyTime(filePath):
	filePath = unicode(filePath,'utf8')
	t = os.path.getmtime(filePath)
	return t
	
def get_FileName(filePath):
	pos = filePath.rfind("\\")
	return filePath[pos+1:]
			
def cczFile(srcPath, outPath):
	cmd = os.path.abspath(expPath) + "\magic.exe -CCZPlsit -S {srcFile} -D {dstPath} -ex {spaceNum} -debug 0".format(srcFile = srcPath, dstPath= outPath, spaceNum = 0)
	print("cmd:" +cmd)
	os.system(cmd)

def checkSurplusFile(srcPath, dstPath):
	srcPath = os.path.abspath(srcPath)
	dstPath = os.path.abspath(dstPath)
	for file in os.listdir(dstPath):
		srcFile = os.path.join(srcPath, file)
		dstFile = os.path.join(dstPath, file)
		# print("srcFile" + srcFile)
		if os.path.isfile(dstFile):
			# print("srcFile" + dstFile)
			if not os.path.exists(srcFile):
				print("the file dest:" + dstFile + "  is 多出来的残余文件，将被删除")
				os.remove(dstFile)
		if os.path.isdir(dstFile):
			checkSurplusFile(srcFile, dstFile)
		
def main():
	resRoot = 'sg'
	desRoot1 = "..\\sgCommon\\res"
	desRoot2 = "..\\sgCommon\\resNew"

	show_params(sys.argv)
	paramsLen = len(sys.argv)
	if paramsLen >= 2:
		resRoot = sys.argv[1]

	srcRoot1 = '..\\{0}\\res'.format(resRoot)
	srcRoot2 = '..\\{0}\\resNew'.format(resRoot)
	
	cczFile(srcRoot1, desRoot1)
	cczFile(srcRoot2, desRoot2)
	checkSurplusFile(srcRoot1, desRoot1)
	checkSurplusFile(srcRoot2, desRoot2)
	
if __name__=="__main__":
	main()