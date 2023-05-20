<?php

use Illuminate\Support\Facades\Route;
use App\Http\Controllers\ContactController;

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider within a group which
| contains the "web" middleware group. Now create something great!
|
*/

Route::get('/', function () {
    return view('welcome');
});
// Route::resource('/contact', ContactController::class);

Route::get('/contact', [ContactController::class, 'index']);
Route::get('/contact/create', [ContactController::class, 'create']);
Route::post('/contact', [ContactController::class, 'store']);
Route::get('/contact/{id}', [ContactController::class, 'show']);
Route::get('/contact/{id}/edit', [ContactController::class, 'edit']);
Route::put('/contact/{id}', [ContactController::class, 'update']);
Route::delete('/contact/{id}', [ContactController::class, 'destroy']);
