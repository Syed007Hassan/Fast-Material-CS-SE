@extends('main')

@section('content')
    <div class="card">
        <div class="card-header">Dashboard</div>
        <div class="card-body"></div>
        <h5 class="card-title">Welcome to Dashboard</h5>
        <p class="card-text">You are logged in as {{ $user->name }}!</p> <!-- display the user's name -->
    </div>
    </div>
@endsection('content')
