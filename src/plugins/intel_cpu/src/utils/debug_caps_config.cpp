// Copyright (C) 2018-2023 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//
#ifdef CPU_DEBUG_CAPS

#include "debug_caps_config.h"

#include <string>

namespace ov {
namespace intel_cpu {

void DebugCapsConfig::readProperties() {
    auto readEnv = [](const char* envVar) {
        return std::getenv(envVar);
    };

    auto parseDumpFormat = [](const std::string& format) {
        if (format == "BIN")
            return FORMAT::BIN;
        else if (format == "TEXT")
            return FORMAT::TEXT;
        else
            IE_THROW() << "readDebugCapsProperties: Unknown dump format";
    };

    const char* envVarValue = nullptr;

    if ((envVarValue = readEnv("OV_CPU_EXEC_GRAPH_PATH")))
        execGraphPath = envVarValue;

    if ((envVarValue = readEnv("OV_CPU_VERBOSE")))
        verbose = envVarValue;

    if ((envVarValue = readEnv("OV_CPU_BLOB_DUMP_DIR")))
        blobDumpDir = envVarValue;

    if ((envVarValue = readEnv("OV_CPU_BLOB_DUMP_FORMAT")))
        blobDumpFormat = parseDumpFormat(envVarValue);

    if ((envVarValue = readEnv("OV_CPU_BLOB_DUMP_NODE_EXEC_ID")))
        blobDumpFilters[BY_EXEC_ID] = envVarValue;

    if ((envVarValue = readEnv("OV_CPU_BLOB_DUMP_NODE_PORTS")))
        blobDumpFilters[BY_PORTS] = envVarValue;

    if ((envVarValue = readEnv("OV_CPU_BLOB_DUMP_NODE_TYPE")))
        blobDumpFilters[BY_TYPE] = envVarValue;

    if ((envVarValue = readEnv("OV_CPU_BLOB_DUMP_NODE_NAME")))
        blobDumpFilters[BY_NAME] = envVarValue;

    if ((envVarValue = readEnv("OV_CPU_SUMMARY_PERF"))) {
        summaryPerf = envVarValue;
    }

    if ((envVarValue = readEnv("OV_CPU_DISABLE")))
        disable.parseAndSet(envVarValue);

    if ((envVarValue = readEnv("OV_CPU_DUMP_IR")))
        dumpIR.parseAndSet(envVarValue);
}

}   // namespace intel_cpu
}   // namespace ov
#endif // CPU_DEBUG_CAPS
