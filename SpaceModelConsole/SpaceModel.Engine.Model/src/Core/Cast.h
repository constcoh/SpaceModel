#pragma once

class Cast {
public:
	template<typename CheckType,typename InstanceType>
	static bool IsPointerOf(const InstanceType* instance)
	{
		return (dynamic_cast<const CheckType*>(instance) != NULL);
	}

	template<typename TargetType, typename InstanceType>
	static TargetType To(InstanceType(&instance))
	{
		return *((TargetType*)(&instance));
	}
};