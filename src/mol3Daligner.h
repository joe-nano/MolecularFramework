/*
 * (c) 2012-2019 gmrandazzo@gmail.com
 * This file is part of MolecularFramework.
 * You can use,modify, and distribute it under
 * the terms of the GNU General Public Licenze, version 3.
 * See the file LICENSE for details
 */
#ifndef MOL3DALIGNER_H
#define MOL3DALIGNER_H
#include <stdio.h>
#include <scientific.h>
#include "molecule.h"


/*
* Finding of optimal rotation and translation between
* corresponding 3D points
* Algorithm: Euclidean/Rigid transform
* Paper: A Method for Registration of 3-D Shapes’, by Besl and McKay, 1992.
*
* Dataset: A, and B
* Rotation: R
* Translation: t
* Equation to solve: B = R*A+t
*
* Algorithm:
* 1) Find the centroid in both datasets
* 2) Bring both dataset to the origin then find the optimal rotation
* 3) Find the translation t
*/

double ComputeRMSD(MOLECULE m1, MOLECULE m2);

/*
 * Move the centre of mass of a molecule to a new one
 */
void TranslateConformation(MOLECULE m, double cx, double cy, double cz);

/*
 * Random rotation in x, y, z of the molecular conformation
 */
void RandomConformationRotation(MOLECULE *m);

/*
 * Align conformers of the same molecule (molecule m1 to molecule m2) according
 * to the global structure and return the rmsd
 */
double Align3DConformations(MOLECULE m1, MOLECULE m2);

/*
 * Align two different molecules (molecule m1 to molecule m2) according
 * to atom id1 (aid1) and atom id2 (aid2) defined by the user.
 * The function return the alignment rmsd.
 */
double Align3DPharmacophore(MOLECULE m1, MOLECULE m2, uivector *aid1, uivector *aid2);

double SimplexAlign3DConformations(MOLECULE m1, MOLECULE m2);

matrix *_Aconf_;
matrix *_Bconf_;

#endif
