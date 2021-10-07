#include <iostream>
#include <vulkan/vulkan.hpp>

static std::string AppName = "InitInstance";
static std::string EngineName = "Vulkan.hpp";

int main(int argc, char** argv)
{
    try
    {
        // initialize the application info
        auto applicationInfo = vk::ApplicationInfo()
            .setPApplicationName(AppName.c_str())
            .setApplicationVersion(1)
            .setPEngineName(EngineName.c_str())
            .setEngineVersion(1)
            .setApiVersion(VK_VERSION_1_2);

        // initialize the instance create info
        auto instanceCreateInfo = vk::InstanceCreateInfo()
            .setFlags(vk::InstanceCreateFlags())
            .setPApplicationInfo(&applicationInfo);

        auto instance = vk::createInstance(instanceCreateInfo);
        instance.destroy();
    }
    catch (vk::SystemError& err)
    {
        std::cout << "vk::SystemError: " << err.what() << std::endl;
        exit(-1);
    }
    catch (std::exception& err)
    {
        std::cout << "std::exception: " << err.what() << std::endl;
        exit(-1);
    }
    catch (...)
    {
        std::cout << "unknown error" << std::endl;
        exit(-1);
    }
    return 0;
}