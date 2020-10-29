#pragma once

/** 初始节点温度 */
#define INIT_CHUNK_TEMPERATURE 500

/** 初始环境温度 */
#define INIT_ENVIRONMENT_TEMPERATUE 100

/** 计算时间上限 */
#define TIME_MAX 600

/** 热导率 (α) */
#define THERMAL_CONDUCTIVITY 0.05

/** 是否考虑凝固 */
#define SOLIDIFICATING false

/** 材料凝固温度 */
#define FREEZING_TEMPERATURE 660

/** 材料凝固潜热 */
#define SOLIDIFICATION_HEAT 398

//--------------------------
// Thermal Conductivity 
//--------------------------

/** 液相导热系数 */
#define LIQUID_THERMAL_CONDUCTIVITY 10

/** 固相导热系数 */
#define SOLID_THERMAL_CONDUCTIVITY 2.28

/** 铸形导热系数 */
#define CAST_THERMAL_CONDUCTIVITY 0.00627

//--------------------------
// Heat Capacity
//--------------------------

/** 液相比热 */
#define LIQUID_HEAT_CAPACITY 1.09

/** 固相比热 */
#define SOLID_HEAT_CAPACITY 1.17

/** 铸形比热 */
#define CAST_HEAT_CAPACITY 0.8987

//--------------------------
// Density
//--------------------------

/** 液相密度 */
#define LIQUID_DENSITY 2.38

/** 固相密度 */
#define SOLID_DENSITY 2.702

/** 铸形密度 */
#define CAST_DENSITY 1.55