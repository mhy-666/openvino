// Copyright (C) 2018-2023 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include <ngraph/node.hpp>
#include <ngraph/variant.hpp>

#include <low_precision/lpt_visibility.hpp>
#include <ngraph/pass/graph_rewrite.hpp>
#include "low_precision/rt_info/shared_value_attribute.hpp"
#include "low_precision/layer_transformation.hpp"
#include "attribute_parameters.hpp"

namespace ngraph {
/**
 * @ingroup ie_transformation_common_api
 * @brief QuantizationGranularityAttribute defines quantization granularity of operation inputs.
 *
 * For more details about the attribute, refer to
 * [QuantizationGranularityAttribute](@ref openvino_docs_OV_UG_lpt_QuantizationGranularity) page in the Inference Engine Developer Guide.
 */
class LP_TRANSFORMATIONS_API QuantizationGranularityAttribute : public ov::RuntimeAttribute {
public:
    OPENVINO_RTTI("LowPrecision::QuantizationGranularity", "", ov::RuntimeAttribute, 0);

    enum class Granularity {
        PerChannel,
        PerTensor
    };

    QuantizationGranularityAttribute() : granularity(Granularity::PerChannel) {}
    QuantizationGranularityAttribute(const Granularity granularity) : granularity(granularity) {}

    bool operator==(const QuantizationGranularityAttribute& attribute) const {
        return this->granularity == attribute.granularity;
    }

    bool is_skipped() const;
    std::string to_string() const override;

    Granularity granularity;
};
} // namespace ngraph
