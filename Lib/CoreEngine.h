#ifndef CORE_ENGINE_H
#define CORE_ENGINE_H
#include "Arduino.h"
struct Device {
    String dev_name;
    String kernel_name;
};

struct Keywords {
    String cmd_name;
    String state;
};
struct Direction {
    String dir_name;
    String dir_value;
};

struct CMD {
    String cmd_name;
    String state;
};

class CoreEngine {
public:
    CoreEngine();
    void processCommand(String command);
    String getCloudCmd();  // Getter for cloud_cmd
    String addCommasToCommand(String command);
    void resetCloudCmd();
    void processLocalCommand(String command);
    String getLocalCmd();  // Getter for local_cmd
    String addCommasToLocalCommand(String command);
    void resetLocalCmd();

private:
    void executeCommand(String subCommand);
    String cloud_cmd;  // Accumulate sub_cloud into cloud_cmd
    static const Device devices[];
    static const Keywords keys[];
    void executeLocalCommand(String subCommand);
    String local_cmd;  // Accumulate sub_cloud into local_cmd
    static const Direction dir[];
    static const CMD cmd[];
};

#endif
