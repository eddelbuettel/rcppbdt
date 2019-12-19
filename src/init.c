#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* FIXME: 
   Check these declarations against the C/Fortran source code.
*/

/* .Call calls */
extern SEXP RcppBDT_charToPOSIXct(SEXP, SEXP);
extern SEXP RcppBDT_cToPOSIXct(SEXP, SEXP);
extern SEXP RcppBDT_toPOSIXct(SEXP, SEXP);

extern SEXP _rcpp_module_boot_bdtDdMod();
extern SEXP _rcpp_module_boot_bdtDtMod();
extern SEXP _rcpp_module_boot_bdtDuMod();
extern SEXP _rcpp_module_boot_bdtPtMod();
extern SEXP _rcpp_module_boot_bdtTzMod();

static const R_CallMethodDef CallEntries[] = {
    {"RcppBDT_charToPOSIXct", (DL_FUNC) &RcppBDT_charToPOSIXct, 2},
    {"RcppBDT_cToPOSIXct",    (DL_FUNC) &RcppBDT_cToPOSIXct,    2},
    {"RcppBDT_toPOSIXct",     (DL_FUNC) &RcppBDT_toPOSIXct,     2},
    {"_rcpp_module_boot_bdtDdMod", (DL_FUNC) &_rcpp_module_boot_bdtDdMod, 0},
    {"_rcpp_module_boot_bdtDtMod", (DL_FUNC) &_rcpp_module_boot_bdtDtMod, 0},
    {"_rcpp_module_boot_bdtDuMod", (DL_FUNC) &_rcpp_module_boot_bdtDuMod, 0},
    {"_rcpp_module_boot_bdtPtMod", (DL_FUNC) &_rcpp_module_boot_bdtPtMod, 0},
    {"_rcpp_module_boot_bdtTzMod", (DL_FUNC) &_rcpp_module_boot_bdtTzMod, 0},
    {NULL, NULL, 0}
};

void R_init_RcppBDT(DllInfo *dll)
{
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
