////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  Embedded Machine Learning Library (EMLL)
//  File:     ModelEx.cpp (compiler)
//  Authors:  Umesh Madan
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "ModelEx.h"
#include "CppBlock.h"

namespace emll
{
	namespace compiler
	{
		model::Port::PortType ModelEx::GetNodeDataType(const model::Node& node)
		{
			return node.GetOutputPorts()[0]->GetType();
		}

		const model::Node* ModelEx::GetSourceNode(const model::PortElementBase& elt)
		{
			return elt.ReferencedPort()->GetNode();
		}

		bool ModelEx::IsLeafNode(const model::Node& node)
		{
			return (node.GetDependentNodes().size() == 0);
		}

		bool ModelEx::IsPureVector(const model::InputPortBase& port)
		{
			auto ranges = port.GetInputElements().GetRanges();
			return (ranges.size() == 1 && ranges[0].Size() > 1);
		}

		bool ModelEx::IsPureBinary(const model::Node& node)
		{
			const std::vector<model::InputPortBase*>& inputs = node.GetInputPorts();
			return (inputs.size() == 2);
		}

		bool ModelEx::IsScalar(const model::InputPortBase& port)
		{
			return (port.Size() == 1);
		}

		bool ModelEx::IsScalar(const model::OutputPortBase& port)
		{
			return (port.Size() == 1);
		}

		bool ModelEx::HasSingleDescendant(const model::Node& node)
		{
			return (node.GetDependentNodes().size() == 1);
		}

		bool ModelEx::HasSingleDescendant(const model::PortElementBase& elt)
		{
			return HasSingleDescendant(*GetSourceNode(elt));
		}
	}
}