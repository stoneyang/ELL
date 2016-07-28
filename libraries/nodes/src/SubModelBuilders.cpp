////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  Embedded Machine Learning Library (EMLL)
//  File:     SubModelBuilders.cpp (nodes)
//  Authors:  Ofer Dekel
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "SubModelBuilders.h"
#include "ConstantNode.h"

namespace nodes
{
    ConstantPredictorSubModelOutputs BuildSubModel(const predictors::ConstantPredictor& predictor, model::Model& model, const model::OutputPortElements<double>& outputPortElements)
    {
        auto constantNode = model.AddNode<ConstantNode<double>>(predictor.GetValue());
        return{ constantNode->output };
    }

    //SingleInputThresholdRuleSubModelOutputs BuildSubModel(const predictors::SingleInputThresholdRule & rule, model::Model & model, const model::OutputPortElements<double>& outputPortElements)
    //{
    //    return SingleInputThresholdRuleSubModelOutputs();
    //}

    // add BinaryPredicateNode with operation less than
    // SingleInput --> SingleElement
    // TreeRoot ---> Root
}