{% import "macros.tmpl" as macros %}
/*
 * Filename: {{filename_nosuffix}}.h
 *
 * Author: Autogenerated by H-DA RTE Generator, (c) Prof. Fromm
 *
 * Description: {{ data.description }}
 */

#ifndef _H_DEFINE_{{filename_nosuffix.upper()}}
#define _H_DEFINE_{{filename_nosuffix.upper()}}

#include "project.h"
#include "global.h"
#include "rte_types.h"

/* USER CODE START {{name.upper()}}_INCLUDES */

/* USER CODE END {{name.upper()}}_INCLUDES */

{% block content %}

{% endblock %}
#endif