void copy_vector_to_array(double *arr, std::vector<double> v)
{
  std::copy(v.begin(), v.end(), arr);
}

double *allocate_double(int n)
{
  double *pointer = (double *)calloc(n, sizeof(double));
  if (pointer == NULL)
  {
    printf("cannot allocate memory\n");
    exit(1);
  }
  return pointer;
}

Fields allocate_fields(int n_points)
{
  Fields fields = {
    alpha : allocate_double(n_points),
    beta_x : allocate_double(n_points),
    beta_y : allocate_double(n_points),
    beta_z : allocate_double(n_points),
    gamma_xx : allocate_double(n_points),
    gamma_xy : allocate_double(n_points),
    gamma_xz : allocate_double(n_points),
    gamma_yy : allocate_double(n_points),
    gamma_yz : allocate_double(n_points),
    gamma_zz : allocate_double(n_points),
    K_xx : allocate_double(n_points),
    K_xy : allocate_double(n_points),
    K_xz : allocate_double(n_points),
    K_yy : allocate_double(n_points),
    K_yz : allocate_double(n_points),
    K_zz : allocate_double(n_points),
    // Hydro
    rho : allocate_double(n_points),
    epsilon : allocate_double(n_points),
    pressure : allocate_double(n_points),
    v_x : allocate_double(n_points),
    v_y : allocate_double(n_points),
    v_z : allocate_double(n_points),
  };
  return fields;
}

void free_fields(Fields *fields)
{
  free(fields->alpha);
  free(fields->beta_x);

  free(fields->beta_y);

  free(fields->beta_z);

  free(fields->gamma_xx);
  free(fields->gamma_xy);
  free(fields->gamma_xz);
  free(fields->gamma_yy);
  free(fields->gamma_yz);
  free(fields->gamma_zz);

  free(fields->K_xx);
  free(fields->K_xy);
  free(fields->K_xz);
  free(fields->K_yy);
  free(fields->K_yz);
  free(fields->K_zz);

  free(fields->rho);
  free(fields->epsilon);
  free(fields->pressure);
  free(fields->v_x);
  free(fields->v_y);
  free(fields->v_z);
}