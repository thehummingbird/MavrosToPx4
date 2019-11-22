
"use strict";

let FileTruncate = require('./FileTruncate.js')
let LogRequestList = require('./LogRequestList.js')
let LogRequestEnd = require('./LogRequestEnd.js')
let WaypointSetCurrent = require('./WaypointSetCurrent.js')
let MessageInterval = require('./MessageInterval.js')
let CommandTriggerControl = require('./CommandTriggerControl.js')
let CommandVtolTransition = require('./CommandVtolTransition.js')
let SetMode = require('./SetMode.js')
let ParamPush = require('./ParamPush.js')
let CommandHome = require('./CommandHome.js')
let MountConfigure = require('./MountConfigure.js')
let CommandBool = require('./CommandBool.js')
let CommandLong = require('./CommandLong.js')
let StreamRate = require('./StreamRate.js')
let FileWrite = require('./FileWrite.js')
let ParamGet = require('./ParamGet.js')
let FileRemoveDir = require('./FileRemoveDir.js')
let CommandTriggerInterval = require('./CommandTriggerInterval.js')
let SetMavFrame = require('./SetMavFrame.js')
let ParamPull = require('./ParamPull.js')
let FileList = require('./FileList.js')
let FileMakeDir = require('./FileMakeDir.js')
let CommandTOL = require('./CommandTOL.js')
let WaypointPull = require('./WaypointPull.js')
let VehicleInfoGet = require('./VehicleInfoGet.js')
let FileClose = require('./FileClose.js')
let WaypointClear = require('./WaypointClear.js')
let CommandInt = require('./CommandInt.js')
let LogRequestData = require('./LogRequestData.js')
let WaypointPush = require('./WaypointPush.js')
let FileRead = require('./FileRead.js')
let FileOpen = require('./FileOpen.js')
let ParamSet = require('./ParamSet.js')
let FileRename = require('./FileRename.js')
let FileChecksum = require('./FileChecksum.js')
let FileRemove = require('./FileRemove.js')

module.exports = {
  FileTruncate: FileTruncate,
  LogRequestList: LogRequestList,
  LogRequestEnd: LogRequestEnd,
  WaypointSetCurrent: WaypointSetCurrent,
  MessageInterval: MessageInterval,
  CommandTriggerControl: CommandTriggerControl,
  CommandVtolTransition: CommandVtolTransition,
  SetMode: SetMode,
  ParamPush: ParamPush,
  CommandHome: CommandHome,
  MountConfigure: MountConfigure,
  CommandBool: CommandBool,
  CommandLong: CommandLong,
  StreamRate: StreamRate,
  FileWrite: FileWrite,
  ParamGet: ParamGet,
  FileRemoveDir: FileRemoveDir,
  CommandTriggerInterval: CommandTriggerInterval,
  SetMavFrame: SetMavFrame,
  ParamPull: ParamPull,
  FileList: FileList,
  FileMakeDir: FileMakeDir,
  CommandTOL: CommandTOL,
  WaypointPull: WaypointPull,
  VehicleInfoGet: VehicleInfoGet,
  FileClose: FileClose,
  WaypointClear: WaypointClear,
  CommandInt: CommandInt,
  LogRequestData: LogRequestData,
  WaypointPush: WaypointPush,
  FileRead: FileRead,
  FileOpen: FileOpen,
  ParamSet: ParamSet,
  FileRename: FileRename,
  FileChecksum: FileChecksum,
  FileRemove: FileRemove,
};
