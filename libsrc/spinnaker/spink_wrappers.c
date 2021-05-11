
SPINK_WRAPPER_ONE_ARG(begin_acquisition,CameraBeginAcquisition,spinCamera,hCam)
SPINK_WRAPPER_ONE_ARG(camera_deinit,CameraDeInit,spinCamera,hCam)
SPINK_WRAPPER_ONE_ARG(clear_cam_list,CameraListClear,spinCameraList,hCamList)
SPINK_WRAPPER_ONE_ARG(clear_iface_list,InterfaceListClear,spinInterfaceList,hIfaceList)
SPINK_WRAPPER_ONE_ARG(connect_spink_cam,CameraInit,spinCamera,hCam)
SPINK_WRAPPER_ONE_ARG(create_empty_cam_list,CameraListCreateEmpty,spinCameraList *,hCamList_p)
SPINK_WRAPPER_ONE_ARG(create_empty_iface_list,InterfaceListCreateEmpty,spinInterfaceList *,hIfaceList_p)
SPINK_WRAPPER_ONE_ARG(create_empty_image,ImageCreateEmpty,spinImage *,hImg_p)
SPINK_WRAPPER_ONE_ARG(destroy_cam_list,CameraListDestroy,spinCameraList,hCamList)
SPINK_WRAPPER_ONE_ARG(destroy_iface_list,InterfaceListDestroy,spinInterfaceList,hIfaceList)
SPINK_WRAPPER_ONE_ARG(destroy_spink_image,ImageDestroy,spinImage,hImg)
SPINK_WRAPPER_ONE_ARG(end_acquisition,CameraEndAcquisition,spinCamera,hCam)
SPINK_WRAPPER_ONE_ARG(get_spink_system,SystemGetInstance,spinSystem *,hSystem_p)
SPINK_WRAPPER_ONE_ARG(release_spink_cam,CameraRelease,spinCamera,hCam)
SPINK_WRAPPER_ONE_ARG(release_interface,InterfaceRelease,spinInterface,hIface)
SPINK_WRAPPER_ONE_ARG(release_spink_image,ImageRelease,spinImage,hImage)
SPINK_WRAPPER_ONE_ARG(release_spink_interface,InterfaceRelease,spinInterface,hIface)
SPINK_WRAPPER_ONE_ARG(release_spink_system,SystemReleaseInstance,spinSystem,hSystem)

SPINK_WRAPPER_TWO_ARG(get_bool_value,BooleanGetValue,spinNodeHandle,hNode,bool8_t *,flag_p)
SPINK_WRAPPER_TWO_ARG(get_camera_node_map,CameraGetNodeMap,spinCamera,hCam,spinNodeMapHandle *,hMap_p)
SPINK_WRAPPER_TWO_ARG(get_cameras_from_system,SystemGetCameras,spinSystem,hSystem,spinCameraList,hCamList)
SPINK_WRAPPER_TWO_ARG(get_current_entry,EnumerationGetCurrentEntry,spinNodeHandle,hNode,spinNodeHandle *,hNode_p)
SPINK_WRAPPER_TWO_ARG(get_device_node_map,CameraGetTLDeviceNodeMap,spinCamera,hCam,spinNodeMapHandle *,hMap_p)
SPINK_WRAPPER_TWO_ARG(get_enum_int_val,EnumerationEntryGetIntValue,spinNodeHandle,hNode,int64_t *, int_ptr)
SPINK_WRAPPER_TWO_ARG(get_float_value,FloatGetValue,spinNodeHandle,hNode,double *,fltptr)
SPINK_WRAPPER_TWO_ARG(get_iface_cameras,InterfaceGetCameras,spinInterface,hIface,spinCameraList *,hCamList_p)
SPINK_WRAPPER_TWO_ARG(get_iface_list,SystemGetInterfaces,spinSystem,hSystem,spinInterfaceList,hIfaceList)
SPINK_WRAPPER_TWO_ARG(get_iface_map,InterfaceGetTLNodeMap,spinInterface,hIface,spinNodeMapHandle *,hMap_p)
SPINK_WRAPPER_TWO_ARG(get_image_height,ImageGetHeight,spinImage,hImg,size_t *,height_p)
SPINK_WRAPPER_TWO_ARG(get_image_status,ImageGetStatus,spinImage,hImg,spinImageStatus *,status_p)
SPINK_WRAPPER_TWO_ARG(get_image_width,ImageGetWidth,spinImage,hImg,size_t *,width_p)
SPINK_WRAPPER_TWO_ARG(get_int_value,IntegerGetValue,spinNodeHandle,hNode,int64_t *,intptr)
SPINK_WRAPPER_TWO_ARG(get_n_cameras,CameraListGetSize,spinCameraList,hCamList,size_t *,num_p)
SPINK_WRAPPER_TWO_ARG(get_next_image,CameraGetNextImage,spinCamera,hCam,spinImage *,img_p)
SPINK_WRAPPER_TWO_ARG(get_n_features,CategoryGetNumFeatures,spinNodeHandle,hNode,size_t *,num_p)
SPINK_WRAPPER_TWO_ARG(get_n_interfaces,InterfaceListGetSize,spinInterfaceList,hIfaceList,size_t *,num_p)
SPINK_WRAPPER_TWO_ARG(get_node_type,NodeGetType,spinNodeHandle,hNode,spinNodeType *,type_p)
SPINK_WRAPPER_TWO_ARG(get_stream_node_map,CameraGetTLStreamNodeMap,spinCamera,hCam,spinNodeMapHandle *,hMap_p)
SPINK_WRAPPER_TWO_ARG(get_transport_level_map,CameraGetTLDeviceNodeMap,spinCamera,hCam,spinNodeMapHandle *,hMap_p)
SPINK_WRAPPER_TWO_ARG(image_is_incomplete,ImageIsIncomplete,spinImage,hImg,bool8_t *,flag_p)
SPINK_WRAPPER_TWO_ARG(node_is_available,NodeIsAvailable,spinNodeHandle,hNode,bool8_t *,flag_p)
SPINK_WRAPPER_TWO_ARG(node_is_implemented,NodeIsImplemented,spinNodeHandle,hNode,bool8_t *,flag_p)
SPINK_WRAPPER_TWO_ARG(node_is_readable,NodeIsReadable,spinNodeHandle,hNode,bool8_t *,flag_p)
SPINK_WRAPPER_TWO_ARG(node_is_writable,NodeIsWritable,spinNodeHandle,hNode,bool8_t *,flag_p)
SPINK_WRAPPER_TWO_ARG(set_enum_int_val,EnumerationSetIntValue,spinNodeHandle,hNode,int64_t , v)

SPINK_WRAPPER_THREE_ARG(convert_spink_image,ImageConvert,spinImage,hSrcImg,spinPixelFormatEnums,fmt,spinImage,hDestImg)
SPINK_WRAPPER_THREE_ARG(fetch_spink_node,NodeMapGetNode,spinNodeMapHandle,hMap,const char *,tag,spinNodeHandle *,hNode_p)
SPINK_WRAPPER_THREE_ARG(get_cam_from_list,CameraListGet,spinCameraList,hCamList,int,idx,spinCamera *,hCam_p)
SPINK_WRAPPER_THREE_ARG(get_entry_symbolic,EnumerationEntryGetSymbolic,spinNodeHandle,hNode,char *,buf,size_t *,buflen_p)
SPINK_WRAPPER_THREE_ARG(get_enum_entry_by_name,EnumerationGetEntryByName,spinNodeHandle,hEnum,const char *, tag,spinNodeHandle *,hdl_p)
SPINK_WRAPPER_THREE_ARG(get_feature_by_index,CategoryGetFeatureByIndex,spinNodeHandle,hNode,int,idx,spinNodeHandle *,hNode_p)
SPINK_WRAPPER_THREE_ARG(get_iface_from_list,InterfaceListGet,spinInterfaceList,hIfaceList,int,idx,spinInterface *,hIface_p)
SPINK_WRAPPER_THREE_ARG(get_node_display_name,NodeGetDisplayName,spinNodeHandle,hNode,char *,buf,size_t *,buflen_p)
SPINK_WRAPPER_THREE_ARG(get_node_short_name,NodeGetName,spinNodeHandle,hNode,char *,buf,size_t *,buflen_p)
SPINK_WRAPPER_THREE_ARG(get_string_value,StringGetValue,spinNodeHandle,hNode,char *,buf,size_t *,num_p)
SPINK_WRAPPER_THREE_ARG(get_tip_value,NodeGetToolTip,spinNodeHandle,hNode,char *,buf,size_t *,buflen_p)
SPINK_WRAPPER_THREE_ARG(node_to_string,NodeToString,spinNodeHandle,hNode,char *,buf,size_t *,num_p)

////////// added

SPINK_WRAPPER_ONE_ARG(get_last_error_code,ErrorGetLast,spinError*,pError)
SPINK_WRAPPER_ONE_ARG(get_last_error_lineno,ErrorGetLastLineNumber,int64_t*,pLineNum)
SPINK_WRAPPER_ONE_ARG(unregister_all_log_events,SystemUnregisterAllLogEvents,spinSystem,hSystem)
SPINK_WRAPPER_ONE_ARG(exec_spink_command,CommandExecute,spinNodeHandle,hNode)
SPINK_WRAPPER_ONE_ARG(destroy_image,ImageDestroy,spinImage,hImage)
SPINK_WRAPPER_ONE_ARG(set_default_color_proc,ImageSetDefaultColorProcessing,spinColorProcessingAlgorithm,algorithm)
SPINK_WRAPPER_ONE_ARG(get_default_color_proc,ImageGetDefaultColorProcessing,spinColorProcessingAlgorithm*,pAlgorithm)
//SPINK_WRAPPER_ONE_ARG(destroy_device_event,DeviceEventDestroy,spinDeviceEvent,hDeviceEvent)
SPINK_WRAPPER_ONE_ARG(destroy_device_event,DeviceEventDestroy,spinDeviceEventData,hDeviceEvent)
SPINK_WRAPPER_ONE_ARG(destroy_image_event,ImageEventDestroy,spinImageEvent,hImageEvent)
SPINK_WRAPPER_ONE_ARG(destroy_arrival_event,ArrivalEventDestroy,spinArrivalEvent,hArrivalEvent)
SPINK_WRAPPER_ONE_ARG(destroy_removal_event,RemovalEventDestroy,spinRemovalEvent,hRemovalEvent)
SPINK_WRAPPER_ONE_ARG(destroy_iface_event,InterfaceEventDestroy,spinInterfaceEvent,hInterfaceEvent)
SPINK_WRAPPER_ONE_ARG(destroy_log_event,LogEventDestroy,spinLogEvent,hLogEvent)
SPINK_WRAPPER_ONE_ARG(create_image_stats,ImageStatisticsCreate,spinImageStatistics*,phStatistics)
SPINK_WRAPPER_ONE_ARG(destroy_image_stats,ImageStatisticsDestroy,spinImageStatistics,hStatistics)
SPINK_WRAPPER_ONE_ARG(enable_all_image_stats,ImageStatisticsEnableAll,spinImageStatistics,hStatistics)
SPINK_WRAPPER_ONE_ARG(disable_all_images_stats,ImageStatisticsDisableAll,spinImageStatistics,hStatistics)
SPINK_WRAPPER_ONE_ARG(enable_grey_image_stats,ImageStatisticsEnableGreyOnly,spinImageStatistics,hStatistics)
SPINK_WRAPPER_ONE_ARG(enable_rgb_image_stats,ImageStatisticsEnableRgbOnly,spinImageStatistics,hStatistics)
SPINK_WRAPPER_ONE_ARG(enable_hsl_image_stats,ImageStatisticsEnableHslOnly,spinImageStatistics,hStatistics)
//SPINK_WRAPPER_ONE_ARG(get_all_image_stats,ImageStatisticsGetAll(

// This one is deprecated in more recent versions of spinnaker...
//SPINK_WRAPPER_ONE_ARG(close_avi_recorder,AVIRecorderClose,spinAVIRecorder,hRecorder)

SPINK_WRAPPER_ONE_ARG(invalidate_spink_node,NodeInvalidateNode,spinNodeHandle,hNode)


SPINK_WRAPPER_TWO_ARG(get_register_address,RegisterGetAddress,spinNodeHandle,hNode,int64_t*,pAddress)
SPINK_WRAPPER_TWO_ARG(get_register_length,RegisterGetLength,spinNodeHandle,hNode,int64_t*,pLength)
SPINK_WRAPPER_TWO_ARG(set_register_ref,RegisterSetReference,spinNodeHandle,hNode,spinNodeHandle,hRef)
SPINK_WRAPPER_TWO_ARG(get_last_error_msg,ErrorGetLastMessage,char*,pBuf,size_t*,pLen)
SPINK_WRAPPER_TWO_ARG(get_last_build_date,ErrorGetLastBuildDate,char*,pBuf,size_t*,pLen)
SPINK_WRAPPER_TWO_ARG(get_last_build_time,ErrorGetLastBuildTime,char*,pBuf,size_t*,pLen)
SPINK_WRAPPER_TWO_ARG(get_last_error_filename,ErrorGetLastFileName,char*,pBuf,size_t*,pLen)
SPINK_WRAPPER_TWO_ARG(get_last_error_full_msg,ErrorGetLastFullMessage,char*,pBuf,size_t*,pLen)
SPINK_WRAPPER_TWO_ARG(get_last_error_funcname,ErrorGetLastFunctionName,char*,pBuf,size_t*,pLen)
SPINK_WRAPPER_TWO_ARG(set_logging_level,SystemSetLoggingLevel,spinSystem,hSystem,spinnakerLogLevel,logLevel)
SPINK_WRAPPER_TWO_ARG(get_logging_level,SystemGetLoggingLevel,spinSystem,hSystem,spinnakerLogLevel*,pLogLevel)
SPINK_WRAPPER_TWO_ARG(register_sys_log_event,SystemRegisterLogEvent,spinSystem,hSystem,spinLogEvent,hLogEvent)
SPINK_WRAPPER_TWO_ARG(unregister_sys_log_event,SystemUnregisterLogEvent,spinSystem,hSystem,spinLogEvent,hLogEvent)
SPINK_WRAPPER_TWO_ARG(system_is_in_use,SystemIsInUse,spinSystem,hSystem,bool8_t*,pbIsInUse)
SPINK_WRAPPER_TWO_ARG(register_sys_arrival_event,SystemRegisterArrivalEvent,spinSystem,hSystem,spinArrivalEvent,hArrivalEvent)
SPINK_WRAPPER_TWO_ARG(register_sys_removal_event,SystemRegisterRemovalEvent,spinSystem,hSystem,spinRemovalEvent,hRemovalEvent)
SPINK_WRAPPER_TWO_ARG(unregister_sys_arrival_event,SystemUnregisterArrivalEvent,spinSystem,hSystem,spinArrivalEvent,hArrivalEvent)
SPINK_WRAPPER_TWO_ARG(unregister_sys_remove_event,SystemUnregisterRemovalEvent,spinSystem,hSystem,spinRemovalEvent,hRemovalEvent)
SPINK_WRAPPER_TWO_ARG(register_sys_interface_event,SystemRegisterInterfaceEvent,spinSystem,hSystem,spinInterfaceEvent,hInterfaceEvent)
SPINK_WRAPPER_TWO_ARG(unregister_sys_interface_event,SystemUnregisterInterfaceEvent,spinSystem,hSystem,spinInterfaceEvent,hInterfaceEvent)
SPINK_WRAPPER_TWO_ARG(update_cameras,SystemUpdateCameras,spinSystem,hSystem,bool8_t*,pbChanged)
//SPINK_WRAPPER_TWO_ARG(spinCameraListRemove,CameraList,hCameraList,size_t,index)
//SPINK_WRAPPER_TWO_ARG(spinCameraListAppend,CameraList,hCameraListBase,spinCameraList,hCameraListToAppend)
//SPINK_WRAPPER_TWO_ARG(spinCameraListRemoveBySerial,CameraList,hCameraList,const char*,pSerial)
//SPINK_WRAPPER_TWO_ARG(spinInterfaceUpdateCameras,Interface,hInterface,bool8_t*,pbChanged)
//SPINK_WRAPPER_TWO_ARG(spinInterfaceGetTLNodeMap,Interface,hInterface,spinNodeMapHandle*,phNodeMap)
SPINK_WRAPPER_TWO_ARG(register_iface_arrival_event,InterfaceRegisterArrivalEvent,spinInterface,hInterface,spinArrivalEvent,hArrivalEvent)
SPINK_WRAPPER_TWO_ARG(register_iface_remove_event,InterfaceRegisterRemovalEvent,spinInterface,hInterface,spinRemovalEvent,hRemovalEvent)
SPINK_WRAPPER_TWO_ARG(unregister_iface_arrival_event,InterfaceUnregisterArrivalEvent,spinInterface,hInterface,spinArrivalEvent,hArrivalEvent)
SPINK_WRAPPER_TWO_ARG(unregister_iface_remove_event,InterfaceUnregisterRemovalEvent,spinInterface,hInterface,spinRemovalEvent,hRemovalEvent)
SPINK_WRAPPER_TWO_ARG(register_iface_iface_event,InterfaceRegisterInterfaceEvent,spinInterface,hInterface,spinInterfaceEvent,hInterfaceEvent)
SPINK_WRAPPER_TWO_ARG(unregister_iface_iface_event,InterfaceUnregisterInterfaceEvent,spinInterface,hInterface,spinInterfaceEvent,hInterfaceEvent)
SPINK_WRAPPER_TWO_ARG(iface_is_in_use,InterfaceIsInUse,spinInterface,hInterface,bool8_t*,pbIsInUse)
SPINK_WRAPPER_TWO_ARG(get_camera_access_mode,CameraGetAccessMode,spinCamera,hCamera,spinAccessMode*,pAccessMode)
SPINK_WRAPPER_TWO_ARG(camera_is_streaming,CameraIsStreaming,spinCamera,hCamera,bool8_t*,pbIsStreaming)
SPINK_WRAPPER_TWO_ARG(register_cam_device_event,CameraRegisterDeviceEvent,spinCamera,hCamera,spinDeviceEventData,hDeviceEvent)
SPINK_WRAPPER_TWO_ARG(unregister_cam_device_event,CameraUnregisterDeviceEvent,spinCamera,hCamera,spinDeviceEvent,hDeviceEvent)
SPINK_WRAPPER_TWO_ARG(register_cam_image_event,CameraRegisterImageEvent,spinCamera,hCamera,spinImageEvent,hImageEvent)
SPINK_WRAPPER_TWO_ARG(unregister_cam_image_event,CameraUnregisterImageEvent,spinCamera,hCamera,spinImageEvent,hImageEvent)
SPINK_WRAPPER_TWO_ARG(camera_is_valid,CameraIsValid,spinCamera,hCamera,bool8_t*,pbValid)
SPINK_WRAPPER_TWO_ARG(camera_is_initialized,CameraIsInitialized,spinCamera,hCamera,bool8_t*,pbInit)
SPINK_WRAPPER_TWO_ARG(discover_cam_max_packet_size,CameraDiscoverMaxPacketSize,spinCamera,hCamera,unsigned int*,pMaxPacketSize)
SPINK_WRAPPER_TWO_ARG(create_spink_image,ImageCreate,spinImage,hSrcImage,spinImage*,phDestImage)
SPINK_WRAPPER_TWO_ARG(get_color_processing,ImageGetColorProcessing,spinImage,hImage,spinColorProcessingAlgorithm*,pAlgorithm)
SPINK_WRAPPER_TWO_ARG(get_image_id,ImageGetID,spinImage,hImage,uint64_t*,pId)
SPINK_WRAPPER_TWO_ARG(get_image_data,ImageGetData,spinImage,hImage,void**,ppData)
SPINK_WRAPPER_TWO_ARG(get_image_private_data,ImageGetPrivateData,spinImage,hImage,void**,ppData)
SPINK_WRAPPER_TWO_ARG(get_image_bufsize,ImageGetBufferSize,spinImage,hImage,size_t*,pSize)
SPINK_WRAPPER_TWO_ARG(image_deep_copy,ImageDeepCopy,spinImage,hSrcImage,spinImage,hDestImage)
SPINK_WRAPPER_TWO_ARG(get_image_offset_x,ImageGetOffsetX,spinImage,hImage,size_t*,pOffsetX)
SPINK_WRAPPER_TWO_ARG(get_image_offset_y,ImageGetOffsetY,spinImage,hImage,size_t*,pOffsetY)
SPINK_WRAPPER_TWO_ARG(get_image_padding_x,ImageGetPaddingX,spinImage,hImage,size_t*,pPaddingX)
SPINK_WRAPPER_TWO_ARG(get_image_padding_y,ImageGetPaddingY,spinImage,hImage,size_t*,pPaddingY)
SPINK_WRAPPER_TWO_ARG(get_image_frame_id,ImageGetFrameID,spinImage,hImage,uint64_t*,pFrameID)
SPINK_WRAPPER_TWO_ARG(get_image_timestamp,ImageGetTimeStamp,spinImage,hImage,uint64_t*,pTimeStamp)
SPINK_WRAPPER_TWO_ARG(get_image_payload_type,ImageGetPayloadType,spinImage,hImage,size_t*,pPayloadType)
SPINK_WRAPPER_TWO_ARG(get_TL_payload_type,ImageGetTLPayloadType,spinImage,hImage,spinPayloadTypeInfoIDs*,pPayloadType)
SPINK_WRAPPER_TWO_ARG(get_image_pixel_format,ImageGetPixelFormat,spinImage,hImage,spinPixelFormatEnums*,pPixelFormat)
SPINK_WRAPPER_TWO_ARG(get_TL_pixel_format,ImageGetTLPixelFormat,spinImage,hImage,uint64_t*,pPixelFormat)
SPINK_WRAPPER_TWO_ARG(get_TL_pixel_format_namespace,ImageGetTLPixelFormatNamespace,spinImage,hImage,spinPixelFormatNamespaceID*,pPixelFormatNamespace)
SPINK_WRAPPER_TWO_ARG(get_valid_image_payload_size,ImageGetValidPayloadSize,spinImage,hImage,size_t*,pSize)
//SPINK_WRAPPER_TWO_ARG(spinImageSaveFromExt,Image,hImage,const char*,pFilename)
//SPINK_WRAPPER_TWO_ARG(spinImageGetChunkLayoutID,Image,hImage,uint64_t*,pId)
SPINK_WRAPPER_TWO_ARG(calc_image_stats,ImageCalculateStatistics,spinImage,hImage,const spinImageStatistics,hStatistics)
SPINK_WRAPPER_TWO_ARG(image_has_crc,ImageHasCRC,spinImage,hImage,bool8_t*,pbHasCRC)
SPINK_WRAPPER_TWO_ARG(check_image_crc,ImageCheckCRC,spinImage,hImage,bool8_t*,pbCheckCRC)
SPINK_WRAPPER_TWO_ARG(get_image_bpp,ImageGetBitsPerPixel,spinImage,hImage,size_t*,pBitsPerPixel)
SPINK_WRAPPER_TWO_ARG(get_image_size,ImageGetSize,spinImage,hImage,size_t*,pImageSize)
SPINK_WRAPPER_TWO_ARG(get_image_stride,ImageGetStride,spinImage,hImage,size_t*,pStride)
SPINK_WRAPPER_TWO_ARG(get_log_data_priority,LogDataGetPriority,spinLogEventData,hLogEventData,int64_t*,pValue)

SPINK_WRAPPER_TWO_ARG(get_dev_event_id,DeviceEventGetId,spinDeviceEventData,hDeviceEventData,uint64_t*,pEventId)
SPINK_WRAPPER_TWO_ARG(get_dev_event_payload,DeviceEventGetPayloadDataSize,spinDeviceEventData,hDeviceEventData,size_t*,pBufSize)
//SPINK_WRAPPER_TWO_ARG(AVIRecorderAppend,spinAVIRecorder,hRecorder,spinImage,hImage)
//SPINK_WRAPPER_TWO_ARG(AVISetMaximumSize,spinAVIRecorder,hRecorder,unsigned int,size)
SPINK_WRAPPER_TWO_ARG(get_num_nodes,NodeMapGetNumNodes,spinNodeMapHandle,hNodeMap,size_t*,pValue)
SPINK_WRAPPER_TWO_ARG(poll_node_map,NodeMapPoll,spinNodeMapHandle,hNodeMap,int64_t,timestamp)
SPINK_WRAPPER_TWO_ARG(get_access_mode,NodeGetAccessMode,spinNodeHandle,hNode,spinAccessMode*,pAccessMode)
SPINK_WRAPPER_TWO_ARG(get_name_space,NodeGetNameSpace,spinNodeHandle,hNode,spinNameSpace*,pNamespace)
SPINK_WRAPPER_TWO_ARG(get_node_visibility,NodeGetVisibility,spinNodeHandle,hNode,spinVisibility*,pVisibility)
SPINK_WRAPPER_TWO_ARG(get_node_caching_mode,NodeGetCachingMode,spinNodeHandle,hNode,spinCachingMode*,pCachingMode)
SPINK_WRAPPER_TWO_ARG(get_node_polling_time,NodeGetPollingTime,spinNodeHandle,hNode,int64_t*,pPollingTime)
SPINK_WRAPPER_TWO_ARG(deregister_node_callback,NodeDeregisterCallback,spinNodeHandle,hNode,spinNodeCallbackHandle,hCb)
SPINK_WRAPPER_TWO_ARG(get_node_imposed_access_mode,NodeGetImposedAccessMode,spinNodeHandle,hNode,spinAccessMode,imposedAccessMode)
SPINK_WRAPPER_TWO_ARG(get_node_imposed_visibility,NodeGetImposedVisibility,spinNodeHandle,hNode,spinVisibility,imposedVisibility)
SPINK_WRAPPER_TWO_ARG(node_from_string,NodeFromString,spinNodeHandle,hNode,const char*,pBuf)
SPINK_WRAPPER_TWO_ARG(set_node_value_string,StringSetValue,spinNodeHandle,hNode,const char*,pBuf)
SPINK_WRAPPER_TWO_ARG(get_max_string_len,StringGetMaxLength,spinNodeHandle,hNode,int64_t*,pValue)
SPINK_WRAPPER_TWO_ARG(set_node_value_int,IntegerSetValue,spinNodeHandle,hNode,int64_t,value)
SPINK_WRAPPER_TWO_ARG(get_node_min_value_int,IntegerGetMin,spinNodeHandle,hNode,int64_t*,pValue)
SPINK_WRAPPER_TWO_ARG(get_node_max_value_int,IntegerGetMax,spinNodeHandle,hNode,int64_t*,pValue)
SPINK_WRAPPER_TWO_ARG(get_node_inc_int,IntegerGetInc,spinNodeHandle,hNode,int64_t*,pValue)
SPINK_WRAPPER_TWO_ARG(get_node_representation_int,IntegerGetRepresentation,spinNodeHandle,hNode,spinRepresentation*,pValue)
SPINK_WRAPPER_TWO_ARG(set_node_value_float,FloatSetValue,spinNodeHandle,hNode,double,value)
SPINK_WRAPPER_TWO_ARG(get_node_min_value_float,FloatGetMin,spinNodeHandle,hNode,double*,pValue)
SPINK_WRAPPER_TWO_ARG(get_node_max_value_float,FloatGetMax,spinNodeHandle,hNode,double*,pValue)
SPINK_WRAPPER_TWO_ARG(get_node_representation_float,FloatGetRepresentation,spinNodeHandle,hNode,spinRepresentation*,pValue)
SPINK_WRAPPER_TWO_ARG(get_n_enum_entries,EnumerationGetNumEntries,spinNodeHandle,hNode,size_t*,pValue)
SPINK_WRAPPER_TWO_ARG(set_enum_enum_value,EnumerationSetEnumValue,spinNodeHandle,hNode,size_t,value)
SPINK_WRAPPER_TWO_ARG(get_enum_int_value,EnumerationEntryGetIntValue,spinNodeHandle,hNode,int64_t*,pValue)
SPINK_WRAPPER_TWO_ARG(get_enum_enum_value,EnumerationEntryGetEnumValue,spinNodeHandle,hNode,size_t*,pValue)
SPINK_WRAPPER_TWO_ARG(set_node_value_bool,BooleanSetValue,spinNodeHandle,hNode,bool8_t,value)
SPINK_WRAPPER_TWO_ARG(get_node_value_bool,BooleanGetValue,spinNodeHandle,hNode,bool8_t*,pbValue)
SPINK_WRAPPER_TWO_ARG(command_is_done,CommandIsDone,spinNodeHandle,hNode,bool8_t*,pbValue)


//SPINK_WRAPPER_THREE_ARG(SystemUpdateCamerasEx,spinSystem,hSystem,bool8_t,bUpdateInterfaces,bool8_t*,pbChanged)
//SPINK_WRAPPER_THREE_ARG(CameraListGetBySerial,spinCameraList,hCameraList,const char*,pSerial,spinCamera*,phCamera)
//SPINK_WRAPPER_THREE_ARG(CameraGetNextImageEx,spinCamera,hCamera,uint64_t,grabTimeout,spinImage*,phImage)
//SPINK_WRAPPER_THREE_ARG(CameraGetUniqueID,spinCamera,hCamera,char*,pBuf,size_t*,pLen)
//SPINK_WRAPPER_THREE_ARG(CameraGetGuiXml,spinCamera,hCamera,char*,pBuf,size_t*,pLen)
//SPINK_WRAPPER_THREE_ARG(CameraRegisterDeviceEventEx,spinCamera,hCamera,spinDeviceEvent,hDeviceEvent,const char*,pName)
SPINK_WRAPPER_THREE_ARG(get_pizel_format_name,ImageGetPixelFormatName,spinImage,hImage,char*,pBuf,size_t*,pLen)
//SPINK_WRAPPER_THREE_ARG(ImageSave,spinImage,hImage,const char*,pFilename,spinImageFileFormat,format)
//SPINK_WRAPPER_THREE_ARG(ImageSavePng,spinImage,hImage,const char*,pFilename,const spinPNGOption*,pOption)
//SPINK_WRAPPER_THREE_ARG(ImageSavePpm,spinImage,hImage,const char*,pFilename,const spinPPMOption*,pOption)
//SPINK_WRAPPER_THREE_ARG(ImageSavePgm,spinImage,hImage,const char*,pFilename,const spinPGMOption*,pOption)
//SPINK_WRAPPER_THREE_ARG(ImageSaveTiff,spinImage,hImage,const char*,pFilename,const spinTIFFOption*,pOption)
//SPINK_WRAPPER_THREE_ARG(ImageSaveJpeg,spinImage,hImage,const char*,pFilename,const spinJPEGOption*,pOption)
//SPINK_WRAPPER_THREE_ARG(ImageSaveJpg2,spinImage,hImage,const char*,pFilename,const spinJPG2Option*,pOption)
//SPINK_WRAPPER_THREE_ARG(ImageSaveBmp,spinImage,hImage,const char*,pFilename,const spinBMPOption*,pOption)
SPINK_WRAPPER_THREE_ARG(get_image_status_description,ImageGetStatusDescription,spinImageStatus,status,char*,pBuf,size_t*,pLen)
SPINK_WRAPPER_THREE_ARG(create_device_event,DeviceEventCreate,spinDeviceEventData*,phDeviceEvent,spinDeviceEventFunction,pFunction,void*,pUserData)
SPINK_WRAPPER_THREE_ARG(create_image_event,ImageEventCreate,spinImageEvent*,phImageEvent,spinImageEventFunction,pFunction,void*,pUserData)
SPINK_WRAPPER_THREE_ARG(create_arrival_event,ArrivalEventCreate,spinArrivalEvent*,phArrivalEvent,spinArrivalEventFunction,pFunction,void*,pUserData)
SPINK_WRAPPER_THREE_ARG(create_removal_event,RemovalEventCreate,spinRemovalEvent*,phRemovalEvent,spinRemovalEventFunction,pFunction,void*,pUserData)
SPINK_WRAPPER_THREE_ARG(create_log_event,LogEventCreate,spinLogEvent*,phLogEvent,spinLogEventFunction,pFunction,void*,pUserData)
SPINK_WRAPPER_THREE_ARG(get_image_stats_channel_status,ImageStatisticsGetChannelStatus,spinImageStatistics,hStatistics,spinStatisticsChannel,channel,bool8_t*,pbEnabled)
SPINK_WRAPPER_THREE_ARG(set_image_stats_channel_status,ImageStatisticsSetChannelStatus,spinImageStatistics,hStatistics,spinStatisticsChannel,channel,bool8_t,bEnable)
SPINK_WRAPPER_THREE_ARG(get_n_image_stats_pixel_values,ImageStatisticsGetNumPixelValues,spinImageStatistics,hStatistics,spinStatisticsChannel,channel,unsigned int*,pNumValues)
SPINK_WRAPPER_THREE_ARG(get_image_mean,ImageStatisticsGetMean,spinImageStatistics,hStatistics,spinStatisticsChannel,channel,float*,pMean)
SPINK_WRAPPER_THREE_ARG(get_image_histogram,ImageStatisticsGetHistogram,spinImageStatistics,hStatistics,spinStatisticsChannel,channel,int**,ppHistogram)
SPINK_WRAPPER_THREE_ARG(get_log_data_category_name,LogDataGetCategoryName,spinLogEventData,hLogEventData,char*,pBuf,size_t*,pLen)
SPINK_WRAPPER_THREE_ARG(get_log_data_priority_name,LogDataGetPriorityName,spinLogEventData,hLogEventData,char*,pBuf,size_t*,pLen)
SPINK_WRAPPER_THREE_ARG(get_log_data_timestamp,LogDataGetTimestamp,spinLogEventData,hLogEventData,char*,pBuf,size_t*,pLen)
SPINK_WRAPPER_THREE_ARG(get_log_data_NDC,LogDataGetNDC,spinLogEventData,hLogEventData,char*,pBuf,size_t*,pLen)
SPINK_WRAPPER_THREE_ARG(get_log_data_thread_name,LogDataGetThreadName,spinLogEventData,hLogEventData,char*,pBuf,size_t*,pLen)
SPINK_WRAPPER_THREE_ARG(get_log_message,LogDataGetLogMessage,spinLogEventData,hLogEventData,char*,pBuf,size_t*,pLen)
SPINK_WRAPPER_THREE_ARG(get_dev_event_payload_data,DeviceEventGetPayloadData,spinDeviceEventData,hDeviceEventData,const uint8_t*,pBuf,size_t*,pBufSize)
SPINK_WRAPPER_THREE_ARG(get_dev_event_name,DeviceEventGetName,spinDeviceEventData,hDeviceEventData,char*,pBuf,size_t*,pLen)
//SPINK_WRAPPER_THREE_ARG(AVIRecorderOpenUncompressed,spinAVIRecorder*,phRecorder,const char*,pName,spinAVIOption,option)
//SPINK_WRAPPER_THREE_ARG(AVIRecorderOpenMJPG,spinAVIRecorder*,phRecorder,const char*,pName,spinMJPGOption,option)
//SPINK_WRAPPER_THREE_ARG(AVIRecorderOpenH264,spinAVIRecorder*,phRecorder,const char*,pName,spinH264Option,option)
SPINK_WRAPPER_THREE_ARG(get_image_chunk_int,ImageChunkDataGetIntValue,spinImage,hImage,const char*,pName,int64_t*,pValue)
SPINK_WRAPPER_THREE_ARG(get_image_chunk_float,ImageChunkDataGetFloatValue,spinImage,hImage,const char*,pName,double*,pValue)
//SPINK_WRAPPER_THREE_ARG(NodeMapGetNodeByIndex,spinNodeMapHandle,hNodeMap,size_t,index,spinNodeHandle*,phNode)
SPINK_WRAPPER_THREE_ARG(node_is_equal,NodeIsEqual,spinNodeHandle,hNodeFirst,spinNodeHandle,hNodeSecond,bool8_t*,pbResult)
SPINK_WRAPPER_THREE_ARG(get_node_description,NodeGetDescription,spinNodeHandle,hNode,char*,pBuf,size_t*,pLen)
SPINK_WRAPPER_THREE_ARG(register_node_callback,NodeRegisterCallback,spinNodeHandle,hNode,spinNodeCallbackFunction,pCbFunction,spinNodeCallbackHandle*,phCb)
//SPINK_WRAPPER_THREE_ARG(NodeFromStringEx,spinNodeHandle,hNode,bool8_t,bVerify,const char*,pBuf)
//SPINK_WRAPPER_THREE_ARG(StringSetValueEx,spinNodeHandle,hNode,bool8_t,bVerify,const char*,pBuf)
//SPINK_WRAPPER_THREE_ARG(IntegerSetValueEx,spinNodeHandle,hNode,bool8_t,bVerify,int64_t,value)
//SPINK_WRAPPER_THREE_ARG(IntegerGetValueEx,spinNodeHandle,hNode,bool8_t,bVerify,int64_t*,pValue)
//SPINK_WRAPPER_THREE_ARG(FloatSetValueEx,spinNodeHandle,hNode,bool8_t,bVerify,double,value)
//SPINK_WRAPPER_THREE_ARG(FloatGetValueEx,spinNodeHandle,hNode,bool8_t,bVerify,double*,pValue)
SPINK_WRAPPER_THREE_ARG(get_float_unit,FloatGetUnit,spinNodeHandle,hNode,char*,pBuf,size_t*,pLen)
SPINK_WRAPPER_THREE_ARG(get_enum_entry_by_index,EnumerationGetEntryByIndex,spinNodeHandle,hNode,size_t,index,spinNodeHandle*,phEntry)
//SPINK_WRAPPER_THREE_ARG(get_enum_entry_by_name,EnumerationGetEntryByName,spinNodeHandle,hNode,const char*,pName,spinNodeHandle*,phEntry)
SPINK_WRAPPER_THREE_ARG(get_enum_entry_symbolic,EnumerationEntryGetSymbolic,spinNodeHandle,hNode,char*,pBuf,size_t*,pLen)
SPINK_WRAPPER_THREE_ARG(get_category_feature_by_index,CategoryGetFeatureByIndex,spinNodeHandle,hNode,size_t,index,spinNodeHandle*,phFeature)
SPINK_WRAPPER_THREE_ARG(get_register,RegisterGet,spinNodeHandle,hNode,uint8_t*,pBuf,int64_t,length)
SPINK_WRAPPER_THREE_ARG(set_register,RegisterSet,spinNodeHandle,hNode,const uint8_t*,pBuf,int64_t,length)
//SPINK_WRAPPER_THREE_ARG(InterfaceGetCamerasEx,spinInterface,hInterface,bool8_t,bUpdateCameras,spinCameraList,hCameraList)

