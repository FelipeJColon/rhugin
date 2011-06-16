/*******************************************************************************
 * The Hugin API 
 *******************************************************************************/

/* 1.6 Errors */

SEXP RHugin_error_code(void);


/* 1.6.1 Handling errors */

SEXP RHugin_error_name(SEXP Scode);
SEXP RHugin_error_description(SEXP Scode);


/* 1.7 Taking advantage of multiple processors */

SEXP RHugin_domain_set_concurrency_level(SEXP Sdomain, SEXP Slevel);
SEXP RHugin_domain_get_concurrency_level(SEXP Sdomain);
SEXP RHugin_domain_set_grain_size(SEXP Sdomain, SEXP Ssize);
SEXP RHugin_domain_get_grain_size(SEXP Sdomain);


/* 2.2 Domains: Creation and deletion */

SEXP RHugin_new_domain(void);
SEXP RHugin_domain_delete(SEXP Sdomain);
SEXP RHugin_domain_clone(SEXP Sdomain);


/* 2.3 Nodes: Creation and deletion */

SEXP RHugin_domain_new_node(SEXP Sdomain, SEXP Scategory, SEXP Skind);
// SEXP RHugin_node_get_domain(SEXP Snode);
SEXP RHugin_node_get_category(SEXP Snodes);
SEXP RHugin_node_get_kind(SEXP Snodes);
// SEXP RHugin_node_set_category(SEXP Snode);
SEXP RHugin_node_delete(SEXP Snodes);
SEXP RHugin_node_clone(SEXP Snode);


/* 2.4 The links of the network */

SEXP RHugin_node_add_parent(SEXP Schild, SEXP Sparents);
SEXP RHugin_node_remove_parent(SEXP Snode, SEXP Sparent);
SEXP RHugin_node_switch_parent(SEXP Snode, SEXP Sold_parent, SEXP Snew_parent);
SEXP RHugin_node_reverse_edge(SEXP Snode1, SEXP Snode2);
SEXP RHugin_node_get_parents(SEXP Snodes);
SEXP RHugin_node_get_children(SEXP Snodes);


/* 2.4.1 The requisite parents and ancestors of decision nodes */

// SEXP RHugin_node_get_requisite_parents(SEXP Snodes);
// SEXP RHugin_node_get_requisite_ancestors(SEXP Snodes);


/* 2.5 The number of states of a node */

SEXP RHugin_node_set_number_of_states(SEXP Snode, SEXP Sstates);
SEXP RHugin_node_get_number_of_states(SEXP Snode);


/* 2.6 The conditional probability and the utility table */

SEXP RHugin_node_get_table(SEXP Snode);
SEXP RHugin_node_touch_table(SEXP Snode);
SEXP RHugin_node_set_alpha(SEXP Snode, SEXP Salpha, SEXP Si);
SEXP RHugin_node_set_beta(SEXP Snode, SEXP Sbeta, SEXP Sparent, SEXP Si);
SEXP RHugin_node_set_gamma(SEXP Snode, SEXP Sgamma, SEXP Si);
SEXP RHugin_node_get_alpha(SEXP Snode, SEXP Si);
SEXP RHugin_node_get_beta(SEXP Snode, SEXP Sparent, SEXP Si);
SEXP RHugin_node_get_gamma(SEXP Snode, SEXP Si);


/* 2.7 The name of a node */

SEXP RHugin_node_set_name(SEXP Snode, SEXP Sname);
SEXP RHugin_node_get_name(SEXP Snode);
SEXP RHugin_domain_get_node_by_name(SEXP Sdomain, SEXP Snames);


/* 2.8 Iterating through the nodes of a domain */

SEXP RHugin_domain_get_first_node(SEXP Sdomain);
SEXP RHugin_node_get_next(SEXP Snode);


/* 2.9.1 Arbitrary user data */

// SEXP RHugin_node_set_user_data(SEXP Snode, SEXP Sdata);
// SEXP RHugin_node_get_user_data(SEXP Snode);
// SEXP RHugin_domain_set_user_data(SEXP Sdomain, SEXP Sdata);
// SEXP RHugin_domain_get_user_data(SEXP Sdomain);


/* 2.9.2 User-defined attributes */

// SEXP RHugin_node_set_attribute(SEXP Snode, SEXP Skey, SEXP Svalue);
// SEXP RHugin_node_get_attribute(SEXP Snode, SEXP Skey);
// SEXP RHugin_domain_set_attribute(SEXP Sdomain, SEXP Skey, SEXP Svalue);
// SEXP RHugin_domain_get_attribute(SEXP Sdomain, SEXP Skey);
// SEXP RHugin_node_get_first_attribute(SEXP Snode);
// SEXP RHugin_domain_get_first_attribute(SEXP Sdomain);
// SEXP RHugin_attribute_get_next(SEXP Sattribute);
// SEXP RHugin_attribute_get_key(SEXP Sattribute);
// SEXP RHugin_attribute_get_value(SEXP Sattribute);


/* 2.10 HUGIN Knowledge Base files */

SEXP RHugin_domain_save_as_kb(SEXP Sdomain, SEXP Sfile_name, SEXP Spassword);
SEXP RHugin_kb_load_domain(SEXP Sfile_name, SEXP Spassword);


/* 4.1 What is a table? */

// SEXP RHugin_table_get_index_from_configuration(SEXP Stable, SEXP Sconfiguration);
// SEXP RHugin_table_get_configuration_from_index(SEXP Stable, SEXP Sconfiguration, SEXP Sindex);


/* 4.2 The nodes and the contents of a table */

SEXP RHugin_table_get_nodes(SEXP Stable);
SEXP RHugin_table_get_data(SEXP Stable);
SEXP RHugin_table_set_data(SEXP Stable, SEXP Sdata);
SEXP RHugin_table_get_mean(SEXP Stable, SEXP Si, SEXP Snode);
SEXP RHugin_table_get_covariance(SEXP Stable, SEXP Si, SEXP Snode1, SEXP Snode2);
SEXP RHugin_table_get_variance(SEXP Stable, SEXP Si, SEXP Snode);


/* 4.3 Deleting tables */

SEXP RHugin_table_delete(SEXP Stable);


/* 4.4 The size of a table */

SEXP RHugin_table_get_size(SEXP Stable);
SEXP RHugin_table_get_cg_size(SEXP Stable);


/* 4.5 Rearranging the contents of a table */

SEXP RHugin_table_reorder_nodes(SEXP Stable, SEXP Sorder);


/* 5.1 Subtyping of discrete nodes */

SEXP RHugin_node_set_subtype(SEXP Snode, SEXP Ssubtype);
SEXP RHugin_node_get_subtype(SEXP Snodes);


/* 5.2 Expressions */

// SEXP RHugin_node_make_expression(SEXP Snode);
// SEXP RHugin_label_make_expression(SEXP Slabel);
// SEXP RHugin_boolean_make_expression(SEXP Sb);
// SEXP RHugin_number_make_expression(SEXP Snumber);
// SEXP RHugin_make_composite_expression(SEXP Soperator, SEXP Sarguments);
// SEXP RHugin_expression_is_composite(SEXP Se);
// SEXP RHugin_expression_get_operator(SEXP Se);
// SEXP RHugin_expression_get_operands(SEXP Se);
// SEXP RHugin_expression_get_node(SEXP Se);
// SEXP RHugin_expression_get_number(SEXP Se);
// SEXP RHugin_expression_get_label(SEXP Se);
// SEXP RHugin_expression_get_boolean(SEXP Se);
// SEXP RHugin_expression_delete(SEXP Se);
// SEXP RHugin_expression_clone(SEXP Se);


/* 5.3 Syntax for expression */

SEXP RHugin_string_parse_expression(SEXP Sstring, SEXP Smodel);
SEXP RHugin_expression_to_string(SEXP Sexpression);


/* 5.4 Creating and maintaining models */

SEXP RHugin_node_new_model(SEXP Snode, SEXP Smodel_nodes);
SEXP RHugin_node_get_model(SEXP Snodes);
SEXP RHugin_model_delete(SEXP Smodels);
SEXP RHugin_model_get_nodes(SEXP Smodel);
SEXP RHugin_model_get_size(SEXP Smodels);
SEXP RHugin_model_set_expression(SEXP Smodel, SEXP Sindex, SEXP Sexpression);
SEXP RHugin_model_get_expression(SEXP Smodel, SEXP Sindex);


/* 5.5 State labels */

SEXP RHugin_node_set_state_label(SEXP Snode, SEXP Ss, SEXP Slabels);
SEXP RHugin_node_get_state_label(SEXP Snode, SEXP Ss);
SEXP RHugin_node_get_state_index_from_label(SEXP Snode, SEXP Slabels);


/* 5.6 State values */

SEXP RHugin_node_set_state_value(SEXP Snode, SEXP Ss, SEXP Svalues);
SEXP RHugin_node_get_state_value(SEXP Snode, SEXP Ss);
SEXP RHugin_node_get_state_index_from_value(SEXP Snode, SEXP Svalues);


/* 5.8 Generating tables */

SEXP RHugin_node_generate_table(SEXP Snodes);
SEXP RHugin_domain_generate_tables(SEXP Sdomain);
// SEXP RHugin_class_generate_tables(SEXP Sclass);
// SEXP RHugin_class_set_log_file(SEXP Sclass, SEXP Slog_file);


/* 5.9 How the computations are done */

SEXP RHugin_model_set_number_of_samples_per_interval(SEXP Smodel, SEXP Scount);
SEXP RHugin_model_get_number_of_samples_per_interval(SEXP Smodel);


/* 6.2 Compilation */

SEXP RHugin_domain_compile(SEXP Sdomain);
SEXP RHugin_domain_is_compiled(SEXP Sdomain);


/* 6.3 Triangulation */

SEXP RHugin_domain_set_max_number_of_separators(SEXP Sdomain, SEXP Scount);
SEXP RHugin_domain_get_max_number_of_separators(SEXP Sdomain);
SEXP RHugin_domain_triangulate(SEXP Sdomain, SEXP Smethod);
SEXP RHugin_domain_triangulate_with_order(SEXP Sdomain, SEXP Sorder);
SEXP RHugin_domain_is_triangulated(SEXP Sdomain);
SEXP RHugin_domain_get_elimination_order(SEXP Sdomain);
// SEXP RHugin_domain_parse_nodes(SEXP Sdomain, SEXP Sfile_name, SEXP Serror_fun, SEXP Sdata);
// SEXP RHugin_class_parse_nodes(SEXP Sclass, SEXP Sfile_name, SEXP Serror_fun, SEXP Sdata);


/* 6.4 Getting a compilation log */

// SEXP RHugin_domain_set_log_file(SEXP Sdomain, SEXP Slog_file)


/* 6.5 Uncompilation */

SEXP RHugin_domain_uncompile(SEXP Sdomain);


/* 6.6 Compression */

SEXP RHugin_domain_compress(SEXP Sdomain);
SEXP RHugin_domain_is_compressed(SEXP Sdomain);


/* 6.7 Approximation */

SEXP RHugin_domain_approximate(SEXP Sdomain, SEXP Sepsilon);
SEXP RHugin_domain_get_approximation_constant(SEXP Sdomain);


/* 7.2 Junction trees */

SEXP RHugin_domain_get_first_junction_tree(SEXP Sdomain);
SEXP RHugin_jt_get_next(SEXP Sjt);
SEXP RHugin_clique_get_junction_tree(SEXP Sclique);
SEXP RHugin_node_get_junction_tree(SEXP Snode);
SEXP RHugin_jt_get_cliques(SEXP Sjt);
SEXP RHugin_jt_get_root(SEXP Sjt);
// SEXP RHugin_jt_get_total_size(SEXP Sjt);
// SEXP RHugin_jt_get_total_cg_size(SEXP Sjt);


/* 7.3 Cliques */

SEXP RHugin_clique_get_members(SEXP Sclique);
SEXP RHugin_clique_get_neighbors(SEXP Sclique);


/* 8.2 Entering evidence */

SEXP RHugin_node_select_state(SEXP Snode, SEXP Sstate);
SEXP RHugin_node_enter_finding(SEXP Snode, SEXP Sstates, SEXP Svalues);
SEXP RHugin_node_enter_value(SEXP Snode, SEXP Svalue);


/* 8.3 Retracting evidence */

SEXP RHugin_node_retract_findings(SEXP Snodes);
SEXP RHugin_domain_retract_findings(SEXP Sdomain);


/* 8.4 Determining independence properties */

SEXP RHugin_domain_get_d_connected_nodes(SEXP Sdomain, SEXP Ssource, SEXP Shard, SEXP Ssoft);
SEXP RHugin_domain_get_d_separated_nodes(SEXP Sdomain, SEXP Ssource, SEXP Shard, SEXP Ssoft);


/* 8.5 Retreiving beliefs */

SEXP RHugin_node_get_belief(SEXP Snode, SEXP Sstates);
SEXP RHugin_node_get_mean(SEXP Snode);
SEXP RHugin_node_get_variance(SEXP Snode);
SEXP RHugin_domain_get_marginal(SEXP Sdomain, SEXP Snodes);
SEXP RHugin_node_get_distribution(SEXP Snode);


/* 8.6 Retrieving expected utilities */

SEXP RHugin_node_get_expected_utility(SEXP Snode, SEXP Sstates);
// SEXP RHugin_domain_get_expected_utility(SEXP Sdomain);


/* 8.7 Computing function values */

// SEXP RHugin_node_get_value(SEXP Snode);


/* 8.8 Examining Evidence */

SEXP RHugin_node_get_entered_finding(SEXP Snode, SEXP Sstates);
SEXP RHugin_node_get_propagated_finding(SEXP Snode, SEXP Sstates);
SEXP RHugin_node_get_entered_value(SEXP Snode);
SEXP RHugin_node_get_propagated_value(SEXP Snode);
SEXP RHugin_node_evidence_is_entered(SEXP Snode);
SEXP RHugin_node_likelihood_is_entered(SEXP Snode);
SEXP RHugin_node_evidence_is_propagated(SEXP Snode);
SEXP RHugin_node_likelihood_is_propagated(SEXP Snode);


/* 8.9 Case files */

SEXP RHugin_domain_save_case(SEXP Sdomain, SEXP Sfile_name);
// SEXP RHugin_domain_parse_case(SEXP Sdomain, SEXP Sfile_name);


/* 9.2 Propagation */

SEXP RHugin_domain_propagate(SEXP Sdomain, SEXP Sequilibrium, SEXP Smode);
SEXP RHugin_jt_propagate(SEXP Sjt, SEXP Sequilibrium, SEXP Smode);


/* 9.3 Inference in LIMIDs: Computing optimal policies */

// SEXP RHugin_domain_update_policies(SEXP Sdomain);


/* 9.4 Conflict of evidence */

SEXP RHugin_domain_get_conflict(SEXP Sdomain);
SEXP RHugin_jt_get_conflict(SEXP Sjt);


/* 9.5 The normalization constant */

SEXP RHugin_domain_get_normalization_constant(SEXP Sdomain);
SEXP RHugin_domain_get_log_normalization_constant(SEXP Sdomain);


/* 9.6 Initializing the inference engine */

SEXP RHugin_domain_save_to_memory(SEXP Sdomain);
SEXP RHugin_domain_reset_inference_engine(SEXP Sdomain);
SEXP RHugin_domain_initialize(SEXP Sdomain);


/* 9.7 Querying the state of the inference engine */

SEXP RHugin_domain_equilibrium_is(SEXP Sdomain, SEXP Sequilibrium);
SEXP RHugin_jt_equilibrium_is(SEXP Sjt, SEXP Sequilibrium);
SEXP RHugin_domain_evidence_mode_is(SEXP Sdomain, SEXP Smode);
SEXP RHugin_jt_evidence_mode_is(SEXP Sjt, SEXP Smode);
SEXP RHugin_domain_evidence_is_propagated(SEXP Sdomain);
SEXP RHugin_jt_evidence_is_propagated(SEXP Sjt);
SEXP RHugin_domain_likelihood_is_propagated(SEXP Sdomain);
SEXP RHugin_jt_likelihood_is_propagated(SEXP Sjt);
SEXP RHugin_domain_cg_evidence_is_propagated(SEXP Sdomain);
SEXP RHugin_jt_cg_evidence_is_propagated(SEXP Sjt);
SEXP RHugin_domain_evidence_to_propagate(SEXP Sdomain);
SEXP RHugin_jt_evidence_to_propagate(SEXP Sjt);
SEXP RHugin_node_evidence_to_propagate(SEXP Snode);
SEXP RHugin_domain_tables_to_propagate(SEXP Sdomain);
SEXP RHugin_jt_tables_to_propagate(SEXP Sjt);


/* 9.8 Simulation */

SEXP RHugin_domain_simulate(SEXP Sdomain);
SEXP RHugin_node_get_sampled_state(SEXP Snode);
SEXP RHugin_node_get_sampled_value(SEXP Snode);
// SEXP RHugin_node_get_sampled_utility(SEXP Snode);
SEXP RHugin_domain_seed_random(SEXP Sdomain, SEXP Sseed);
SEXP RHugin_domain_get_uniform_deviate(SEXP Sdomain);
SEXP RHugin_domain_get_normal_deviate(SEXP Sdomain, SEXP Smean, SEXP Svariance);


/* 9.9 Value of information analysis */

SEXP RHugin_node_get_entropy(SEXP Snodes);
SEXP RHugin_node_get_mutual_information(SEXP Snodes, SEXP Sothers);


/* Section 9.10 Sensitivity analyis */

SEXP RHugin_node_compute_sensitivity_data(SEXP Snode, SEXP Sstate);
SEXP RHugin_node_get_sensitivity_constants(SEXP Snode, SEXP Sindex);
SEXP RHugin_domain_get_sensitivity_set(SEXP Sdomain);
// SEXP RHugin_domain_compute_sensitivity_data(SEXP Sdomain, SEXP Snodes, SEXP Sstates);
// SEXP RHugin_node_get_sensitivity_constants_by_output(SEXP Snode, SEXP Sinput, SEXP Soutput);
// SEXP RHugin_domain_get_sensitivity_set_by_output(SEXP Sdomain, SEXP Soutput);


/* 9.11 Most probable configurations */

// SEXP RHugin_domain_find_map_configurations(SEXP Sdomain, SEXP Snodes, SEXP Spmin);
// SEXP RHugin_domain_get_number_of_map_configurations(SEXP Sdomain);
// SEXP RHugin_domain_get_map_configuration(SEXP Sdomain, SEXP Sindex);
// SEXP RHugin_domain_get_probability_of_map_configuration(SEXP Sdomain, SEXP Sindex);


/* 10.1 Experience counts and fading factors */

SEXP RHugin_node_get_experience_table(SEXP Snode);
SEXP RHugin_node_has_experience_table(SEXP Snode);
SEXP RHugin_node_get_fading_table(SEXP Snode);
SEXP RHugin_node_has_fading_table(SEXP Snode);


/* 10.2 Updating tables */

SEXP RHugin_domain_adapt(SEXP Sdomain);


/* 11.1 Data */

SEXP RHugin_domain_set_number_of_cases(SEXP Sdomain, SEXP Scount);
SEXP RHugin_domain_new_case(SEXP Sdomain);
SEXP RHugin_domain_get_number_of_cases(SEXP Sdomain);
SEXP RHugin_node_set_case_state(SEXP Snode, SEXP Scase_indices, SEXP Sstates);
SEXP RHugin_node_get_case_state(SEXP Snode, SEXP Scase_indices);
SEXP RHugin_node_set_case_value(SEXP Snode, SEXP Scase_indices, SEXP Svalues);
SEXP RHugin_node_get_case_value(SEXP Snode, SEXP Scase_indices);
SEXP RHugin_node_unset_case(SEXP Snode, SEXP Scase_indices);
SEXP RHugin_node_case_is_set(SEXP Snode, SEXP Scase_indices);
SEXP RHugin_domain_set_case_count(SEXP Sdomain, SEXP Scase_indices, SEXP Scase_counts);
SEXP RHugin_domain_get_case_count(SEXP Sdomain, SEXP Scase_indices);
SEXP RHugin_domain_enter_case(SEXP Sdomain, SEXP Scase_index);


/* 11.2 Scoring of graphical models */

SEXP RHugin_domain_get_log_likelihood(SEXP Sdomain);
SEXP RHugin_domain_get_AIC(SEXP Sdomain);
SEXP RHugin_domain_get_BIC(SEXP Sdomain);


/* 11.3 Data files */

SEXP RHugin_domain_parse_cases(SEXP Sdomain, SEXP Sfile_name);
SEXP RHugin_domain_save_cases(SEXP Sdomain, SEXP Sfile_name, SEXP Snodes,
    SEXP Scases, SEXP Sinclude_case_counts,
    SEXP Sseparator, SEXP Smissing_data);


/* 11.4 Learning network structure */

SEXP RHugin_domain_learn_structure(SEXP Sdomain);
SEXP RHugin_domain_set_significance_level(SEXP Sdomain, SEXP Sprobability);
SEXP RHugin_domain_get_significance_level(SEXP Sdomain);


/* 11.5 Domain knowledge */

SEXP RHugin_node_set_edge_constraint(SEXP Sa, SEXP Sb, SEXP Sconstraint);
SEXP RHugin_node_get_edge_constraint(SEXP Sa, SEXP Sb);


/* 11.6 Learning conditional probability tables */

SEXP RHugin_domain_learn_tables(SEXP Sdomain);
SEXP RHugin_domain_set_log_likelihood_tolerance(SEXP Sdomain, SEXP Stolerance);
SEXP RHugin_domain_get_log_likelihood_tolerance(SEXP Sdomain);
SEXP RHugin_domain_set_max_number_of_em_iterations(SEXP Sdomain, SEXP Scount);
SEXP RHugin_domain_get_max_number_of_em_iterations(SEXP Sdomain);
// SEXP RHugin_domain_learn_class_tables(SEXP Sdomain);


/* 12.8 parsing NET files */

SEXP RHugin_net_parse_domain(SEXP Sfile_name);
// SEXP RHugin_net_parse_classes(SEXP Sfile_name);
SEXP RHugin_domain_save_as_net(SEXP Sdomain, SEXP Sfile_name);


/* 12.9 Saving class collections, classes, and domains as NET files */

// SEXP RHugin_cc_save_as_net(SEXP Scc, SEXP Sfile_name);
// SEXP RHugin_class_save_as_net(SEXP Sclass, SEXP Sfile_name);
// SEXP RHugin_domain_save_as_net(SEXP Sdomain, SEXP Sfile_name);
// SEXP RHugin_class_get_file_name(SEXP Sclass);
// SEXP RHugin_domain_get_file_name(SEXP Sdomain);


/* 13.1 The label of a node */

// SEXP RHugin_node_set_label(SEXP Snode, SEXP Slabel);
// SEXP RHugin_node_get_label(SEXP Snode);


/*  13.2 The position of a node */

SEXP RHugin_node_set_position(SEXP Snode, SEXP Sposition);
SEXP RHugin_node_get_position(SEXP Snode);


/* 13.3 The size of a node */

SEXP RHugin_domain_set_node_size(SEXP Sdomain, SEXP Ssize);
SEXP RHugin_domain_get_node_size(SEXP Sdomain);
// SEXP RHugin_class_set_node_size(SEXP Sclass, SEXP Ssize);
// SEXP RHugin_class_get_node_size(SEXP Sclass);
