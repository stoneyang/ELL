////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  Embedded Machine Learning Library (EMLL)
//  File:     CompilableSum.cpp (compile)
//  Authors:  Ofer Dekel
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "CompilableSum.h"

void CompilableSum::operator=(const layers::Sum& sum)
{
    layers::Sum::operator=(sum);
}

void CompilableSum::operator=(const layers::Layer& layer)
{
    operator=(dynamic_cast<const Sum&>(layer));
}

void CompilableSum::SetActions(uint64_t currentLayerIndex, DataFlowGraph& graph) const
{
    for(uint64_t elementIndex = 0; elementIndex < GetOutputDimension(); ++elementIndex)
    {
        layers::Coordinate thisCoordinate(currentLayerIndex, elementIndex);

        auto& thisNode = graph.GetNode(currentLayerIndex, elementIndex);

        // skip empty action lists
        if(thisNode.HasActions() == false)
        {
            continue;
        }

        for(uint64_t i = 0; i < _inputCoordinates[elementIndex].Size(); ++i)
        {
            auto inputCoordinate = _inputCoordinates[elementIndex][i];
            auto& inputNode = graph.GetNode(inputCoordinate);
            inputNode.EmplaceAction(thisCoordinate);
            
            // increment the input counter
            thisNode.IncrementUncomputedInputs();
        }
    }
}