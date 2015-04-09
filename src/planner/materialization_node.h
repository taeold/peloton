/**
 * @brief Header for materialization plan node.
 *
 * Copyright(c) 2015, CMU
 */

#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "common/types.h"
#include "planner/abstract_plan_node.h"

namespace nstore {

namespace catalog {
  class Schema;
}

namespace planner {

class MaterializationNode : public AbstractPlanNode {
 public:
  MaterializationNode(
    std::vector<AbstractPlanNode *> &&children,
    std::unordered_map<id_t, id_t> &&old_to_new_cols,
    std::vector<std::string> &&column_names,
    catalog::Schema *schema);

  std::unordered_map<id_t, id_t> &old_to_new_cols();

  const std::vector<std::string> &column_names() const;

  const catalog::Schema &schema() const;

 private:
  /**
   * @brief Mapping of old column ids to new column ids after materialization.
   */
  std::unordered_map<id_t, id_t> old_to_new_cols_;

  /** @brief Names of the respective columns. */
  std::vector<std::string> column_names_;

  /** @brief Schema of newly materialized tile. */
  std::unique_ptr<catalog::Schema> schema_;
};

} // namespace planner
} // namespace nstore