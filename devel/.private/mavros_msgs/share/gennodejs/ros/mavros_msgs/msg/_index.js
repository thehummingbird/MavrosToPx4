
"use strict";

let Altitude = require('./Altitude.js');
let ManualControl = require('./ManualControl.js');
let HilControls = require('./HilControls.js');
let StatusText = require('./StatusText.js');
let HilGPS = require('./HilGPS.js');
let RadioStatus = require('./RadioStatus.js');
let Trajectory = require('./Trajectory.js');
let LandingTarget = require('./LandingTarget.js');
let ADSBVehicle = require('./ADSBVehicle.js');
let HomePosition = require('./HomePosition.js');
let WaypointList = require('./WaypointList.js');
let GlobalPositionTarget = require('./GlobalPositionTarget.js');
let OnboardComputerStatus = require('./OnboardComputerStatus.js');
let WheelOdomStamped = require('./WheelOdomStamped.js');
let Vibration = require('./Vibration.js');
let LogEntry = require('./LogEntry.js');
let FileEntry = require('./FileEntry.js');
let AttitudeTarget = require('./AttitudeTarget.js');
let DebugValue = require('./DebugValue.js');
let PositionTarget = require('./PositionTarget.js');
let OverrideRCIn = require('./OverrideRCIn.js');
let State = require('./State.js');
let RTCM = require('./RTCM.js');
let ExtendedState = require('./ExtendedState.js');
let TimesyncStatus = require('./TimesyncStatus.js');
let VFR_HUD = require('./VFR_HUD.js');
let Thrust = require('./Thrust.js');
let Waypoint = require('./Waypoint.js');
let CompanionProcessStatus = require('./CompanionProcessStatus.js');
let RCIn = require('./RCIn.js');
let CommandCode = require('./CommandCode.js');
let BatteryStatus = require('./BatteryStatus.js');
let Mavlink = require('./Mavlink.js');
let ParamValue = require('./ParamValue.js');
let VehicleInfo = require('./VehicleInfo.js');
let HilActuatorControls = require('./HilActuatorControls.js');
let RCOut = require('./RCOut.js');
let ActuatorControl = require('./ActuatorControl.js');
let WaypointReached = require('./WaypointReached.js');
let MountControl = require('./MountControl.js');
let Param = require('./Param.js');
let LogData = require('./LogData.js');
let HilStateQuaternion = require('./HilStateQuaternion.js');
let CamIMUStamp = require('./CamIMUStamp.js');
let OpticalFlowRad = require('./OpticalFlowRad.js');
let HilSensor = require('./HilSensor.js');

module.exports = {
  Altitude: Altitude,
  ManualControl: ManualControl,
  HilControls: HilControls,
  StatusText: StatusText,
  HilGPS: HilGPS,
  RadioStatus: RadioStatus,
  Trajectory: Trajectory,
  LandingTarget: LandingTarget,
  ADSBVehicle: ADSBVehicle,
  HomePosition: HomePosition,
  WaypointList: WaypointList,
  GlobalPositionTarget: GlobalPositionTarget,
  OnboardComputerStatus: OnboardComputerStatus,
  WheelOdomStamped: WheelOdomStamped,
  Vibration: Vibration,
  LogEntry: LogEntry,
  FileEntry: FileEntry,
  AttitudeTarget: AttitudeTarget,
  DebugValue: DebugValue,
  PositionTarget: PositionTarget,
  OverrideRCIn: OverrideRCIn,
  State: State,
  RTCM: RTCM,
  ExtendedState: ExtendedState,
  TimesyncStatus: TimesyncStatus,
  VFR_HUD: VFR_HUD,
  Thrust: Thrust,
  Waypoint: Waypoint,
  CompanionProcessStatus: CompanionProcessStatus,
  RCIn: RCIn,
  CommandCode: CommandCode,
  BatteryStatus: BatteryStatus,
  Mavlink: Mavlink,
  ParamValue: ParamValue,
  VehicleInfo: VehicleInfo,
  HilActuatorControls: HilActuatorControls,
  RCOut: RCOut,
  ActuatorControl: ActuatorControl,
  WaypointReached: WaypointReached,
  MountControl: MountControl,
  Param: Param,
  LogData: LogData,
  HilStateQuaternion: HilStateQuaternion,
  CamIMUStamp: CamIMUStamp,
  OpticalFlowRad: OpticalFlowRad,
  HilSensor: HilSensor,
};
