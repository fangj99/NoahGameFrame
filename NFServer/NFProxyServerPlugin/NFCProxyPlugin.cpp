// -------------------------------------------------------------------------
//    @FileName      :    NFCProxyPlugin.h
//    @Author           :    LvSheng.Huang
//    @Date             :    2013-05-06
//    @Module           :    NFCProxyPlugin
//
// -------------------------------------------------------------------------


#include "NFCProxyPlugin.h"
#include "NFCProxyLogicModule.h"

//
//
#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
#if NF_PLATFORM == NF_PLATFORM_WIN
    SetConsoleTitle("NFProxyServer");
#endif
    CREATE_PLUGIN(pm, NFProxyPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFProxyPlugin)
};

#endif
//////////////////////////////////////////////////////////////////////////

const int NFProxyPlugin::GetPluginVersion()
{
    return 0;
}

const std::string NFProxyPlugin::GetPluginName()
{
    return GET_CLASS_NAME(NFProxyPlugin)
}

void NFProxyPlugin::Install()
{

    REGISTER_MODULE(pPluginManager, NFIProxyLogicModule, NFCProxyLogicModule)

}

void NFProxyPlugin::Uninstall()
{
    UNREGISTER_MODULE(pPluginManager, NFIProxyLogicModule, NFCProxyLogicModule)
}
