#!python   
# -*- coding: utf-8 -*-

import createClass as cs
import createFunc as cf

#创建类
createClass = cs.createClass

#扩展类 内容
extendClass = cs.extendClass

#将扩展的内容写入文件
addExternFuncInfo = cs.addExternInfo

#保存类
saveClass = cs.saveFile

addCallClassContent = cs.addCallClassContent

#在一个类中获取一个调用
getCallClsContent = cs.getCallClsContent

#生成函数调用示例
getCallFuncLine = cf.getFunCallingLine
